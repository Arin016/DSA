#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
vector<vector<int>> g;
vector<int> vis;

void dfs(int node){
    vis[node] = 1;
    for(auto x:g[node]){
        if(!vis[x]){
            dfs(x);
        }
    }
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1, 0);
    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ncmp = 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            ncmp++;
        }
    }
    cout<<ncmp-1<<endl;
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
