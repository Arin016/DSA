#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
vector<vector<pair<int, int>>> g;
vector<int> vis, dis;
void bfs01(int start){
    vis.assign(n+1, 0);
    dis.assign(n+1, 1e18);
    deque<int> q;
    dis[start] = 0;
    q.push_back(start);
    while(!q.empty()){
        auto cur = q.front();
        q.pop_front();
        if(vis[cur])continue;
        vis[cur] = 1;
        for(auto v:g[cur]){
            int x = v.first, wt = v.second;
            if(dis[x]>dis[cur]+wt){
                dis[x]=dis[cur]+wt;
                if(wt)q.push_back(x);
                else q.push_front(x);
            }
        }
    }
}

void solve(){
    g.clear();
    vis.clear();
    dis.clear();
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back({y, 0});
        g[y].push_back({x, 1});
    }
    bfs01(1);
    if(dis[n]==1e18)cout<<-1<<endl;
    else cout<<dis[n]<<endl;
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
