#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
vector<vector<int>> g, nex;
vector<int> depth;
vector<int> partial;

void dfs(int node, int par, int d){
    nex[node][0] = par;
    depth[node] = d;
    for(int i=1;i<20;i++){
        nex[node][i] = nex[nex[node][i-1]][i-1];
    }
    for(auto x:g[node]){
        if(x!=par){
            dfs(x, node, d+1);
        }
    }
}

int LCA(int u, int v){
    if(depth[v]>depth[u])swap(u, v);
    for(int i=19;i>=0;i--){
        if(((depth[u]-depth[v])>>i)&1){
            u = nex[u][i];
        }
    }
    if(u==v)return u;
    for(int i=19;i>=0;i--){
        if(nex[u][i]!=nex[v][i]){
            u = nex[u][i];
            v = nex[v][i];
        }
    }
    return nex[u][0];
}

void addpath(int u, int v, int z){
    partial[u]+=z;
    partial[v]+=z;
    partial[LCA(u, v)]-=z;
    partial[nex[LCA(u, v)][0]]-=z;
}

void dfs1(int node, int par){
    for(auto x:g[node]){
        if(x!=par){
            dfs1(x, node);
            partial[node]+=partial[x];
        }
    }
}
 
void solve(){
    cin>>n;
    g.resize(n+1);
    nex.assign(n+1, vector<int>(20, 0));
    depth.resize(n+1);
    partial.resize(n+1);
    for(int i=0;i<n-1;i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0, 0);
    int q;
    cin>>q;
    while(q--){
        int x, y, z;
        cin>>x>>y>>z;
        addpath(x, y, z);
    }
    dfs1(1, 0);
    for(int i=1;i<=n;i++){
        cout<<partial[i]<<" ";
    }
    cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        g.clear();
        nex.clear();
        depth.clear();
        partial.clear();
        solve();
    }
}
