#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first 
#define S second 
int n, m, k;
vector<string> a;
// the state configuration changes from (shortest path to i, j) to (shortest path to i, j with k walls broken) 
int vis[101][101][101];
int dis[101][101][101];

int dx[] = {-1, +1, 0, 0};
int dy[] = {0, 0, +1, -1};

bool isvalid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

vector<pair<pair<int, int>, int>> neighbours(int x, int y, int kk) {
    vector<pair<pair<int, int>, int>> ans;
    for (int kkk = 0; kkk < 4; kkk++) {
        int nx = x + dx[kkk], ny = y + dy[kkk];
        if (isvalid(nx, ny)) {
            if(a[nx][ny]=='#'){
                if(kk+1<=k){
                    ans.push_back({{nx, ny}, kk+1});
                }
            }
            else{
                ans.push_back({{nx, ny}, kk});
            }
        }
    }
    return ans;
}

void bfs(pair<int, int> start) {
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            for (int kk = 0; kk < 101; kk++) {
                dis[i][j][kk] = 1e18;
                vis[i][j][kk] = 0;
            }
        }
    }
    // queue always holds the state
    queue<pair<pair<int, int>, int>> q;
    dis[start.first][start.second][0] = 0;
    q.push({start, 0});

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (vis[cur.first.first][cur.first.second][cur.second]) continue;
        vis[cur.first.first][cur.first.second][cur.second] = 1;

        for (auto x : neighbours(cur.first.first, cur.first.second, cur.second)) {
            int i = x.first.first, j = x.first.second, kk = x.second;
            if (dis[i][j][kk] > dis[cur.first.first][cur.first.second][cur.second] + 1) {
                dis[i][j][kk] = dis[cur.first.first][cur.first.second][cur.second] + 1;
                q.push({{i, j}, kk});
            }
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    a.assign(n, ""); 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    pair<int, int> start, end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'S') {
                start = {i, j};
            } else if (a[i][j] == 'F') {
                end = {i, j};
            }
        }
    }

    bfs(start);
    
    int mini = 1e18;
    for (int kk = 0; kk <= k; kk++) {
        mini = min(mini, dis[end.first][end.second][kk]);
    }
    cout << mini << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
