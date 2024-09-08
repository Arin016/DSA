#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
vector<vector<int>> g;
vector<int> vis;
bool isbipartite;

void dfs(int node, int color){
    vis[node] = color;
    for(auto x:g[node]){
        if(!vis[x]){
            dfs(x, color^3);
        }
        else if(vis[x]==color){
            isbipartite = false;
            return;
        }
    }
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1, 0);
    isbipartite = true;
    map<pair<int, int>, int> edgecnt;
    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        if(x==y){
            //self loop
            continue;
        }
        if(x>y)swap(x, y);
        edgecnt[{x, y}]++;
        if(edgecnt[{x, y}]>1){
            //multi edge
            continue;
        }
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i] and isbipartite){
            dfs(i, 1);
        }
    }
    if(isbipartite)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
