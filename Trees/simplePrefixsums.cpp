#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

//given a tree of n nodes and weighted edges, find the sum of path of Q different simple paths as queries
//values are on edges you have to push them onto nodes below them!
//keep such a value on root node that doesnt affect your operations on paths
//eg in sum its 0 in max its -1e9 and in min its 1e9
//#####and when you push values like this you dont include LCA node in your answer##### 

vector<vector<pair<int,int>>> g;
vector<int> dep;
vector<vector<int>> nex;
vector<int> prefix;

void dfs(int node, int parent, int depth, int val){
    prefix[node] = prefix[parent]+val;
    dep[node] = depth;
    nex[node][0] = parent;

    for(int i=1;i<20;i++){
        nex[node][i] = nex[nex[node][i-1]][i-1];
    }

    for(auto v:g[node]){
        if(v.first!=parent){
            dfs(v.first,node,depth+1,v.second);
        }
    }
}



int lca(int u,int v){
    if(dep[u]<dep[v]){
        swap(u,v);
    }

    for(int i=19;i>=0;i--){
        if((dep[u]-dep[v])&(1<<i)){
            u = nex[u][i];
        }
    }

    if(u==v){
        return u;
    }

    for(int i=19;i>=0;i--){
        if(nex[u][i]!=nex[v][i]){
            u = nex[u][i];
            v = nex[v][i];
        }
    }

    return nex[u][0];
}

void solve(){
    int n;
    cin>>n;
    g.resize(n+1);
    nex = vector<vector<int>> (n+1,vector<int>(20,0));
    dep.resize(n+1);
    prefix.assign(n+1,0);

    for(int i=0;i<n-1;i++){
        int a,b,w;
        cin>>a>>b>>w;
        g[a].push_back({b,w});
        g[b].push_back({a,w});
    }

    dfs(1,0,0,0);
    
    int q;
    cin>>q;
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<prefix[u]+prefix[v]-2*prefix[lca(u,v)]<<endl;
    }

    g.clear();
    nex.clear();
    prefix.clear();
    dep.clear();
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