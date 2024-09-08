#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
vector<vector<int>> g;
vector<int> vis;
vector<int> topo;

void dfs(int node){
    vis[node] = 1;
    for(auto x:g[node]){
        if(!vis[x]){
            dfs(x);
        }
    }
    topo.push_back(node);
}

//undirected hota toh in out dp!
int rec(int node){ //longest path starting at node in ""directed graph""!!
    //base case
    if(g[node].empty()){ // if no outgoing edges
        return 1;
    }
    //cache check
    if(dp[node] != -1) return dp[node];
    //compute
    int ans = 0;
    for(auto x : g[node]){
        ans = max(ans, 1 + rec(x));
    }
    //save and return
    return dp[node] = ans;
}


void solve(){
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1, 0);
    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    reverse(topo.begin(), topo.end());
    for(auto x:topo){
        cout<<x<<" ";
    }
    cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
