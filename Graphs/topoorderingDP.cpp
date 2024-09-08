#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
vector<vector<int>> g;
vector<int> dp;
vector<int> topo;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;
    for(auto x : g[node]){
        if(!visited[x]){
            dfs(x);
        }
    }
    topo.push_back(node);  // postorder push for topological sort
}

void solve(){
    cin >> n >> m;
    g.assign(n + 1, vector<int>());
    dp.assign(n + 1, 0);
    visited.assign(n + 1, false);
    
    // Read edges
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    
    // Perform DFS to get topological order
    for(int i = 1; i <= n; i++) {
        if(!visited[i]){
            dfs(i);
        }
    }
    
    // Reverse topo vector to get the correct topological order
    reverse(topo.begin(), topo.end());

    // Base case
    dp[1] = 1;
    
    // DP over topological order
    for(auto x : topo) {
        for(auto y : g[x]){
            dp[y] = (dp[y] + dp[x]) % mod;
        }
    }

    // Output the result for node `n`
    cout << dp[n] << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t=1;
    //cin >> t;
    while(t--){
        solve();
    }
}
