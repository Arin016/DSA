#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


int n, m;
vector<vector<int>> g; 
vector<int> vis, par;
bool iscycle;

void dfs(int node, int parent){
    vis[node] = 2;
    par[node] = parent;
    for(auto x:g[node]){
        if(x==parent)continue; //added this line
        if(vis[x]==1){//FE
            dfs(x, node);
        }
        else if(vis[x]==2){//BE
            if(!iscycle){
                vector<int> anycycle;
                int cur = node;
                while(cur!=x){
                    anycycle.push_back(cur);
                    cur = par[cur];
                }
                anycycle.push_back(cur);
            }
            iscycle = true;
        }
    }
    vis[node] = 3;
}


void solve(){
    cin>>n>>m;
    g.resize(n+1);
    iscycle = false;
    vis.assign(n+1, 1);
    par.assign(n+1, -1);
    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y); 
        g[y].push_back(x); //cross edges are impossible in undirected graphs!
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==1){
            dfs(i, -1);
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
