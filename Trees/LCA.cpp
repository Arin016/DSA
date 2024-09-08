#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

//lca = lowest common ancestor
//tree needs to be rooted for lca
//brute: store the paths from both node to parents and look for the first common ancestor (common suffix's first element) by iterating from behind

//LCA based problems keep the nodes from 1 indexed
//finding LCA using BL:
//step 1: get to same level (use BL)
//step 2:jump simultaneously upwards till not same
//check jumps from some 2^i 2^(i-1) 2^(i-2) .... 
//(only jump to that node when the destination nodes are not same)
vector<vector<int>> g;
vector<vector<int>> nex; //stores nodes youd reach to on BLing
//nex[x][i]-->stores the node youd get to if you go 2^i steps from x
vector<int> depth;


//O(nLogn)
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

//O(Logn)
int LCA(int u, int v){
    if(depth[u]<depth[v]){
        swap(u, v);
        //making sure always u is lower in the tree than v
    }
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
    return nex[u][0]; //returning the parent after doing all that above wala gaandmasti!
}

void solve(){

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
