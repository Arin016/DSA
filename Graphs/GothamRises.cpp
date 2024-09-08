#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m, c, r;
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
    g.clear();
    vis.clear();
    cin>>n>>m>>c>>r;
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
    vector<vector<int>> cc(color);
    for(int i=1;i<=n;i++){
        cc[vis[i]].push_back(i);
    }
    if(r+c<=c+c){
        int ans = 0;
        for(int i=1;i<color;i++){
            ans+=c+r*(cc[i].size()-1);
        }
        cout<<ans<<endl;
    }
    else{
        cout<<n*c<<endl;
    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
