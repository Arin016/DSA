#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


int n, m;
vector<vector<int>> g;
vector<int> vis;
// vector<int> subtreesz;
vector<int> tin, low;
int timer;

//computation
int totalcomp = 0;
vector<int> extra; //on deleting that node how many extra components will arise
// vector<vector<int>> extrasubtree; 

void dfs(int node, int par){
    vis[node] = 1;
    // subtreesz[node] = 1;
    tin[node] = low[node] = timer++;
    int child = 0;
    vector<int> childs;
    for(auto x:g[node]){
        if(x==par)continue;
        if(!vis[x]){
            childs.push_back(x);
            dfs(x, node);
            // subtreesz[node]+=subtreesz[x];
            low[node] = min(low[node], low[x]);
            child++;
        }
        else if(vis[x]){ //backedge
            low[node] = min(low[node], tin[x]); //tin[x] ke saath hi lena hai low[x] ke sath nahi!!!
        }
    }
    if(par==-1){ //if this is a root
        extra[node] = child-1;
        //acche se sochke likh yeh wala!
        // extrasubtree[node].push_back(subtreesz[x]);
    }
    else{ //not a root node
        for(auto x:childs){
            if(low[x]>=tin[node]){
                //this x would break into a new component
                extra[node]++;
                // extrasubtree[node].push_back(subtreesz[x]);
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1, 0);
    // subtreesz.assign(n+1, 0);
    tin.assign(n+1, 0);
    low.assign(n+1, 0);
    extra.assign(n+1, 0); 
    // extrasubtree.assign(n+1, vector<int>());
    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    timer = 1;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            totalcomp++;
            dfs(i, -1);
        }
    }
    //answer!!
    for(int i=1;i<=n;i++){
        cout<<totalcomp+extra[i]<<endl;
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
