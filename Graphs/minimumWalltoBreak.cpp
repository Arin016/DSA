#include <bits/stdc++.h>
using namespace std;
#define int long long


//01BFS! use deque
int n, m;
vector<string> a;
vector<vector<bool>> vis;
vector<vector<int>> dis;

int dx[] = {-1, +1, 0, 0};
int dy[] = {0, 0, +1, -1};

bool isvalid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

vector<pair<int, int>> neighbours(int x, int y){
    vector<pair<int, int>> ans;
    for (int kk = 0; kk < 4; kk++) {
        int nx = x + dx[kk], ny = y + dy[kk];
        if (isvalid(nx, ny)) {
            ans.emplace_back(nx, ny);
        }
    }
    return ans;
}

void bfs(pair<int, int> start){
    vis.assign(n, vector<bool>(m, false));
    dis.assign(n, vector<int>(m, 1e18)); 
    
    deque<pair<int, int>> q;
    dis[start.first][start.second] = 0;

    q.push_back(start);
    while (!q.empty()) {
        auto cur = q.front();
        q.pop_front();
        
        if (vis[cur.first][cur.second]) continue;
        vis[cur.first][cur.second] = 1;

        for (auto x : neighbours(cur.first, cur.second)) {
            int i = x.first, j = x.second;
            if(a[i][j]!='#'){ //if wall, go with 1 cost
                if (dis[i][j] > dis[cur.first][cur.second] + 0) {
                    dis[i][j] = dis[cur.first][cur.second] + 0;
                    q.push_front({i, j});
                }
            }
            else{ //go free!
                if (dis[i][j] > dis[cur.first][cur.second] + 1) {
                    dis[i][j] = dis[cur.first][cur.second] + 1;
                    q.push_back({i, j});
                }
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
            else if (a[i][j] == 'F') {
                end = {i, j};
            }
        }
    }

    bfs(start);

    if (dis[end.first][end.second] == 1e18) {
        cout << -1 << "\n";
    } else {
        cout << dis[end.first][end.second] << "\n";
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
