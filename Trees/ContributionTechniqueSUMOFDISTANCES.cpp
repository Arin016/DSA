#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<vector<int>> g;
vector<int> parent, subtreesz;

void dfs(int node, int par){
    parent[node] = par;
    subtreesz[node] = 1;
    for(auto x : g[node]){
        if(x != par){
            dfs(x, node);
            subtreesz[node] += subtreesz[x];
        }
    }
}

void solve(){
    cin >> n;
    g.resize(n + 1);
    parent.resize(n + 1);
    subtreesz.resize(n + 1);
    vector<pair<int, int>> edges;
    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
        g[x].push_back(y);
        g[y].push_back(x);
    }  
    dfs(1, -1);  // Initialize the subtree sizes

    // Edge contribution technique
    int ans = 0;
    for(auto x : edges){
        int u = x.first, v = x.second;
        if (parent[u] == v) swap(u, v);  // Ensure `u` is parent of `v`
        ans += subtreesz[v] * (n - subtreesz[v]);
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
