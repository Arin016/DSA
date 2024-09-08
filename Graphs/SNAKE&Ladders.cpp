#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = LLONG_MAX;

int n, m;
vector<vector<pair<int, int>>> g;
vector<int> vis, dis;

int di[] = {1, 2, 3, 4, 5, 6};

bool isvalid(int x) {
    return (x <= 100) and (x >= 1);
}

void bfs01(int start) {
    vis.assign(101, 0);
    dis.assign(101, INF);

    deque<int> q;
    dis[start] = 0;
    q.push_front(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();

        if (vis[cur]) continue;
        vis[cur] = 1;

        for (auto v : g[cur]) {
            int x = v.first, wt = v.second;
            if (dis[x] > dis[cur] + wt) {
                dis[x] = dis[cur] + wt;
                if (wt == 0) q.push_front(x);
                else q.push_back(x);
            }
        }
    }
}

void solve() {
    g.assign(101, vector<pair<int, int>>());

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back({y, 0});  // Ladder
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back({y, 0});  // Snake
    }

    for (int i = 1; i <= 100; i++) {
        if (g[i].empty()) {  // Only add dice rolls if no snake or ladder
            for (int k = 0; k < 6; k++) {
                int ni = i + di[k];
                if (isvalid(ni)) {
                    g[i].push_back({ni, 1});  // Regular dice roll with weight 1
                }
            }
        }
    }

    bfs01(1);

    if (dis[100] == INF) {
        cout << -1 << endl;  // Impossible to reach square 100
    } else {
        cout << dis[100] << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
