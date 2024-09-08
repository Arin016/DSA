#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


int n;
vector<vector<int>> g;
vector<vector<int>> nex;
vector<int> depth;

void dfs(int node, int par, int d){
    nex[node][0] = par;
    depth[node] = d;
    //building the structure
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
    if(depth[v]>depth[u]){
        swap(u, v);
    }
    //step 1:
    //bringing to same level using binary lifting
    for(int i=19;i>=0;i--){
        if(((depth[u]-depth[v])>>i)&1){
            u = nex[u][i];
        }
    }
    if(u==v)return u;
    //step 2:
    //finding the LCA
    for(int i=19;i>=0;i--){
        if(nex[u][i]!=nex[v][i]){
            u = nex[u][i];
            v = nex[v][i];
        }
    }
    return nex[u][0]; //returning the parent after doing all that above wala gaandmasti!
}

void solve(){
    cin>>n;
    g.resize(n+1);
    depth.resize(n+1);
    nex.assign(n+1, vector<int>(21, 0));
    for(int i=0;i<n-1;i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0, 0);
    int q;
    cin>>q;
    while(q--){
        int u, v, z;
        cin>>u>>v>>z;
        int I = LCA(u, v);
        int a = LCA(u, z);
        int b = LCA(v, z);

        //part 1: the branch that contains u
        //part 2: the branch that conatins v
        //part 3: the branch that contains z
        //blue node is lca of u v with a global root 
        //recall the mental picture from the video editorial

        //if z lies in the branch of u then lca(u, v) == lca(v, z), that blue node from picture
        //then lca of u, v when rooted at z would be lca(u, z)

        //if z lies in the branch of v then lca(u, v) == lca(u, z), that blue node from picture
        //then lca of u, v when rooted at z would be lca(v, z)

        //if z lies in part 3 then lca wrt to z would be equal to lca wrt to the root

        if(I == b){
            cout<<a<<endl;
        }
        else if(I == a){
            cout<<b<<endl;
        }
        else{
            cout<<I<<endl;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        g.clear();
        depth.clear();
        nex.clear();
        solve();
    }
}
