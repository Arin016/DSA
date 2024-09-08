#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
vector<vector<pair<int, int>>> g;
vector<int> vis, dis;


void bfs01(int start){
    vis.assign(n+1, 0);
    dis.assign(n+1, 1e9);
    deque<int> dq;
    dis[start] = 0;
    dq.push_back(start);
    while(!dq.empty()){
        auto cur = dq.front();
        dq.pop_front();
        if(vis[cur])continue;
        vis[cur] = 1;
        for(auto x:g[cur]){
            int neigh = x.first;
            int wt = x.second;
            if(dis[neigh]>dis[cur]+wt){
                dis[neigh] = dis[cur]+wt;
                if(wt==0)dq.push_front(neigh);
                else dq.push_back(neigh);
            }
        }
    }
}   

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int x, y, w;
        cin>>x>>y>>w;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }
    int start;
    cin>>start;


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
