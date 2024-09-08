#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<vector<int>> g;
vector<int> vis,par,dep;
bool is_cycle;
int n,m;
int cycle_len = 1e9;

void dfs(int node, int parent, int depth){
    vis[node] = 2;
    par[node] = parent;
    dep[node] = depth;
    for(auto v:g[node]){
        if(v == par[node])continue;
        if(vis[v]==1){ //forward edge 2 ---> 1
            dfs(v,node,depth+1);
        }
        else if(vis[v]==2){ //back edge 2 ---> 2
            is_cycle = 1;
            cycle_len = min(cycle_len,dep[node]-dep[v]+1);
        }
        else if(vis[v]==3){ //cross edge 2 ---> 3
            
        }
    }
    vis[node] = 3;
}



void solve(){
   cin>>n>>m;
   g.resize(n+1);
   for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    if(a==b){
        //self loop
    }else{
        g[a].push_back(b);
        g[b].push_back(a);
    }
   }

   
   is_cycle=0;
   for(int i=1;i<=n;i++){
        par.assign(n+1,0);
        vis.assign(n+1,1);
        dep.assign(n+1,0);
        dfs(i,0,0);
   }

    if(is_cycle){
        cout<<cycle_len<<endl;
    }else{
        cout<<-1<<endl;
    }
    
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}