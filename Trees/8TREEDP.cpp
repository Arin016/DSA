#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
vector<vector<int>> graph;
vector<int> A;

vector<int> dp; // dp(node) --> max(st.line path, bend path from that node as its LCA or within the nodes subtree)
vector<int> g;  // g(node) --> max path you can go in a st line in node's subtree!

void dfs(int node, int par) {
    g[node] = A[node];
    dp[node] = A[node];
    int maxi1 = -1e9, maxi2 = -1e9;
    for(auto x : graph[node]) { 
        if(x != par) {
            dfs(x, node);
            // g(node) = max(end it here, continue it furthur)
            g[node] = max(g[node], g[node] + g[x]);
            if(g[x] > maxi1) {
                maxi2 = maxi1;
                maxi1 = g[x];
            } else if(g[x] > maxi2) {
                maxi2 = g[x];
            }
        }
    }
    dp[node] = max(g[node], maxi1 + maxi2 + A[node]);
}

void solve() {
    cin >> n;
    graph.assign(n, vector<int>());
    A.assign(n, 0);
    dp.assign(n, 0);
    g.assign(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--; // Assuming 1-based indexing, adjust to 0-based
        graph[u].push_back(v);
        graph[v].push_back(u);
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
