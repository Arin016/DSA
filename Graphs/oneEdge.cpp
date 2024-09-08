#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


int n, m;
vector<vector<int>> g;
vector<int> vis;

void dfs(int node, int color){
    vis[node] = color;
    for(auto x:g[node]){
        if(!vis[x]){
            dfs(x, color);
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
    int color = 1;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i, color);
            color++;
        }
    }
    vector<vector<int>> cc;
    cc.resize(color);
    for(int i=1;i<=n;i++){
        cc[vis[i]].push_back(i);
    }
    int total = 0;
    for(int i=1;i<cc.size();i++){
        total+=cc[i].size();
    }
    int ans = 0;
    for(int i=1;i<cc.size();i++){
        ans+=cc[i].size()*(total-cc[i].size());
    }
    cout<<ans/2<<endl;

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
