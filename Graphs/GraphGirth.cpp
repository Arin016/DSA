#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
vector<vector<int>> g;
vector<int> vis, dis, par;
int ans;

void bfs(int start){
    vis.assign(n+1, 0);
    dis.assign(n+1, 1e18);
    par.assign(n+1, -1);
    queue<int> q;
    dis[start] = 0;
    q.push(start);
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        if(vis[cur])continue;
        vis[cur] = 1;
        for(auto x:g[cur]){
            if(dis[x]>dis[cur]+1){ //first and final relaxation, relaxation edge
                dis[x] = dis[cur]+1;
                par[x] = cur;
                q.push(x);
            }
            else{   //presence of a cycle! //not THE relaxation edge
                if(x==par[cur])continue;   //not the x--par[x] edge
                ans = min(ans, dis[x]+dis[cur]+1); //certainly a cycle edge  ----x---<-start-->--cur---
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    ans = 1e18;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    //considering all cycles through node i, if any
    for(int i=1;i<=n;i++){
        bfs(i);
    }
    if(ans==1e18)cout<<-1<<endl;
    else cout<<ans<<endl;
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
