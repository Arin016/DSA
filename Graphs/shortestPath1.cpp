#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;


// Custom comparator for priority_queue
class comp{
    public:
    bool operator()(pair<int, int> p1, pair<int, int> p2){
        return p1.second > p2.second;
    }
};


int n, m;
vector<vector<pair<int, int>>> g;
vector<int> vis, dis;

void dijk(int start) {
    vis.assign(n+1, 0);
    dis.assign(n+1, 1e18);
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq; //(node, dis)
    dis[start] = 0;
    pq.push({start, 0});

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        int node = cur.first;
        if (vis[node]) continue;
        vis[node] = 1;

        for (auto x : g[node]) {
            int next = x.first;
            int weight = x.second;
            //if (!vis[next] and dis[next] > dis[node] + weight)
            if (dis[next] > dis[node] + weight) {
                dis[next] = dis[node] + weight;
                pq.push({next, dis[next]});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    g.resize(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    dijk(1); 

    for (int i = 1; i <= n; i++) {
        cout << (dis[i]) << " "; 
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}