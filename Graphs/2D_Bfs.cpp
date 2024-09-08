#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
vector<string> a;
vector<vector<bool>> vis;
vector<vector<int>> dis, paths;
vector<vector<pair<int, int>>> par;

int dx[] = {-1, +1, 0, 0};
int dy[] = {0, 0, +1, -1};

bool isvalid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m && (a[x][y] != '#');
}

vector<pair<int, int>> neighbours(int x, int y){
    vector<pair<int, int>> ans;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (isvalid(nx, ny)) {
            ans.emplace_back(nx, ny);
        }
    }
    return ans;
}

void bfs(pair<int, int> start){
    vis.assign(n, vector<bool>(m, 0));
    dis.assign(n, vector<int>(m, 1e18)); 
    par.assign(n, vector<pair<int, int>>(m, {-1, -1}));
    paths.assign(n, vector<int>(m, 0));

    queue<pair<int, int>> q;
    dis[start.first][start.second] = 0;
    paths[start.first][start.second] = 1;
    q.push(start);

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (vis[cur.first][cur.second]) continue;
        vis[cur.first][cur.second] = 1;

        for (auto x : neighbours(cur.first, cur.second)) {
            int i = x.first, j = x.second;
            if (dis[i][j] > dis[cur.first][cur.second] + 1) {
                dis[i][j] = dis[cur.first][cur.second] + 1;
                par[i][j] = {cur.first, cur.second};
                paths[i][j] = paths[cur.first][cur.second];
                q.push({i, j});
            }
            else if (dis[i][j] == dis[cur.first][cur.second] + 1) {
                paths[i][j] += paths[cur.first][cur.second];
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    a.assign(n, ""); 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    pair<int, int> start, end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'S') {
                start = {i, j};
            }
            else if (a[i][j] == 'E') {
                end = {i, j};
            }
        }
    }

    bfs(start);
    
    if (dis[end.first][end.second] == 1e18) {
        cout << -1 << "\n";
    } else {
        cout << dis[end.first][end.second] << "\n";
        cout << paths[end.first][end.second] << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
