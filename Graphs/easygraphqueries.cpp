#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


int n, m, q;
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
    cin>>n>>m>>q;
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
    cc.resize(color+1);
    for(int i=1;i<=n;i++){
        cc[vis[i]].push_back(i);
    }
    while(q--){
        int ch;
        cin>>ch;
        if(ch==1){
            int x;
            cin>>x;
            cout<<cc[vis[x]].size()<<endl;
        }
        else if(ch==2){
            int x, y;
            cin>>x>>y;
            if(vis[x]==vis[y])cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
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
