//if edge weights are given!!
//delta denotes changes!
#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
vector<vector<pair<int, int>>> graph; //delta
vector<int> A;

vector<int> dp; // dp(node) --> max(st.line path, bend path from that node as its LCA or within the nodes subtree)
vector<int> g;  // g(node) --> max path you can go in a st line in node's subtree!

void dfs(int node, int par) {
    g[node] = 0;//delta
    dp[node] = 0;
    int maxi1 = -1e9, maxi2 = -1e9;
    for(auto v : graph[node]) { 
        int x = v.first; //delta
        int wt = v.second;
        if(x != par) {
            dfs(x, node);
            // g(node) = max(end it here, continue it furthur)
            g[node] = max(g[node], g[node]+ wt + g[x]);
            if(g[x] + wt > maxi1) { //delta
                maxi2 = maxi1;
                maxi1 = g[x] + wt;
            } else if(g[x] + wt > maxi2) { //delta
                maxi2 = g[x] + wt;
            }
        }
    }
    dp[node] = max(g[node], maxi1 + maxi2); 
}

void solve() {
    cin >> n;
    graph.assign(n, vector<pair<int, int>>());
    A.assign(n, 0);
    dp.assign(n, 0);
    g.assign(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--; // Assuming 1-based indexing, adjust to 0-based
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    dfs(0, -1); // Assuming node 0 as the root

    int result = *max_element(dp.begin(), dp.end());
    cout << result << '\n';
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
