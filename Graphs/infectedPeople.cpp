#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
vector<vector<int>> a;
vector<pair<int, int>> twos;

bool isvalid(int x, int y) {
    return x >= 0 and x < n and y >= 0 and y < m and a[x][y] != 0;
}

int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};

vector<pair<int, int>> neighbours(int x, int y) {
    vector<pair<int, int>> ans;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (isvalid(nx, ny)) {
            ans.push_back({nx, ny});
        }
    }
    return ans;
}

vector<vector<int>> vist, dist;

void bfst() {
    vist.assign(n, vector<int>(m, 0));
    dist.assign(n, vector<int>(m, 1e18));
    queue<pair<int, int>> q;
    for (auto x : twos) {
        dist[x.first][x.second] = 0;
        q.push({x.first, x.second});
    }
    while (!q.empty()) {
        auto cur = q.front();
        int curx = cur.first;
        int cury = cur.second;
        q.pop();
        if (vist[curx][cury]) continue;
        vist[curx][cury] = 1;
        for (auto x : neighbours(curx, cury)) {
            int nx = x.first, ny = x.second;
            if (dist[nx][ny] > dist[curx][cury] + 1) {
                dist[nx][ny] = dist[curx][cury] + 1;
                q.push({nx, ny});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    a.resize(n, vector<int>(m, 0));
    twos.clear();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) twos.push_back({i, j});
        }
    }
    bfst();
    int tmax = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                tmax = max(tmax, dist[i][j]);
            }
        }
    }
    if(tmax==1e18)cout<<-1<<endl;
    else cout << tmax << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
