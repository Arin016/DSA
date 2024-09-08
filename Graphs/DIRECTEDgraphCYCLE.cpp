#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


int n, m;
vector<vector<int>> g; 
vector<int> vis, par;
vector<int> ispartofcycle;
vector<int> prefixorder;
bool iscycle;

void dfs(int node, int parent){
    vis[node] = 2;
    par[node] = parent;
    for(auto x:g[node]){
        if(vis[x]==1){//forward edge node --> x 2----->1
            dfs(x, node);
        }
        else if(vis[x]==2){ //back edge node --> x 2----->2
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
            ispartofcycle[node]++;
            ispartofcycle[par[x]]--;
        }
        else if(vis[x]==3){ //cross edge node --> x 2----->3

        }
    }
    vis[node] = 3;
    prefixorder.push_back(node);
}

//if we reomve all of backward edges and cross edges we'd get a tree and thats called DFS tree!!

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    iscycle = false;
    vis.assign(n+1, 1);
    par.assign(n+1, -1);
    ispartofcycle.assign(n+1, 0);
    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y); //x-->y y is a neighbour of x!
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==1){
            dfs(i, -1);
        }
    }
    for(auto x:prefixorder){
        ispartofcycle[par[x]] += ispartofcycle[x];
    }
    int cntnodespartofcycle = 0;
    for(int i=1;i<=n;i++){
        if(ispartofcycle[i]>0){
            cntnodespartofcycle++;
        }
    }
    cout<<cntnodespartofcycle<<endl;
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
