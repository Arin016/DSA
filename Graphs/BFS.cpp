#include<bits/stdc++.h>
using namespace std;
#define int int64_t

int mod = 1e9+7;

int n, m;
vector<vector<int>> g;
vector<int> vis, dis;

void bfs(int start) {
    vis.assign(n + 1, 0);
    dis.assign(n + 1, 1e9);
    queue<int> q;
    dis[start] = 0;
    q.push(start);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if(vis[cur]) continue;
        vis[cur] = 1;
        for(auto x : g[cur]) {
            if(dis[x] > dis[cur] + 1) {
                dis[x] = dis[cur] + 1;
                q.push(x);
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    g.assign(n + 1, vector<int>()); 
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(1);
    // Uncomment below lines if you need to print the distances
    // for(int i = 1; i <= n; i++) {
    //     cout << dis[i] << " ";
    // }
    // cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}
