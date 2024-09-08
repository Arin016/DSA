#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
vector<vector<int>> g;
vector<int> vis;
vector<int> par;
vector<int> anycycle;
bool iscycle;

void dfs(int node, int parent){
    vis[node] = 2;
    par[node] = parent;
    for(auto x:g[node]){
        if(x==parent)continue;
        if(vis[x]==1){ //forward edge
            dfs(x, node);
        }
        else if(vis[x]==2){ //back edge
            if(!iscycle){
                int cur = node;
                while(cur!=x){
                    anycycle.push_back(cur);
                    cur = par[cur];
                }
                anycycle.push_back(x);
                reverse(anycycle.begin(), anycycle.end());
            }
            iscycle = 1;
            return;
        }
        else if(vis[x]==3){ //cross edge

        }
    }
    vis[node] = 3;
}

void solve(){
    cin>>n>>m;
    g.clear();
    vis.clear();
    par.clear();
    g.resize(n+1);
    vis.assign(n+1, 1);
    par.assign(n+1, -1);
    iscycle = false;
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
            //multiple edges
            continue;
        }
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==1 and !iscycle){
            dfs(i, -1);
        }
    }
    if(iscycle)cout<<"YES"<<endl;
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
