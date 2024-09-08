#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


int n, m;
vector<vector<int>> g;
vector<int> vis, tin, low;
int timer;
//
int totalcomp;
vector<int> extracmp;

void dfs(int node, int par){
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    vector<int> children;
    for(auto x:g[node]){
        if(x==par)continue;
        if(!vis[x]){
            children.push_back(x);
            dfs(x, node);
            low[node] = min(low[node], low[x]);
        }
        else if(vis[x]){
            low[node] = min(low[node], tin[x]);
        }
    }
    if(par==-1){ //if root node
        extracmp[node] = (int)(children.size())-1;
    }
    else{   //if not a root node
        for(auto x:children){
            if(low[x]>=tin[node]){
                extracmp[node]++;
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1, 0);
    low.assign(n+1, 0);
    tin.assign(n+1, 0);
    extracmp.assign(n+1, 0);
    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    timer = 1;
    totalcomp = 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            totalcomp++;
            dfs(i, -1);
        }
    }
    cout<<"total component before any deletion"<<" : "<<totalcomp<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<" : "<<totalcomp+extracmp[i]<<endl;
    }
    //for node--->x to be a bridge low[x]>tin[node]
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
