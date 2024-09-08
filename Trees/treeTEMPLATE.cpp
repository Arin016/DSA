#include<bits/stdc++.h>
using namespace std;
#define int long long

int mod = 1e9+7;

int n;
vector<vector<int>> g;
vector<int> parent, depth, subtreesz, noofchild;
vector<bool> isleaf;

void dfs(int node, int par, int d){
    depth[node] = d;
    parent[node] = par;
    subtreesz[node] = 1;
    for(auto x: g[node]){
        if(x != par){ // x != par to avoid counting the parent node
            noofchild[node]++;
            dfs(x, node, d+1);
            subtreesz[node] += subtreesz[x];
        }
    }
    if(noofchild[node] == 0) isleaf[node] = true; // Leaf if it has no children
}

void solve(){
    cin >> n;
    
    g.assign(n + 1, vector<int>());
    parent.assign(n + 1, -1);
    depth.assign(n + 1, 0);
    isleaf.assign(n + 1, false);
    subtreesz.assign(n + 1, 0);
    noofchild.assign(n + 1, 0);

    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1, 0, 0); 

    int u, v;
    cin>>u>>v;
    //dist between u and v?
    //run a dfs from root=u and depth[v] will give distance

    //path from u to v??
    vector<int> path;
    int cur = v;
    while(cur!=u){
        path.push_back(cur);
        cur = parent[cur];
    }
    reverse(path.begin(), path.end());
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
