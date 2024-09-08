#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
vector<int> c;
vector<vector<pair<int, int>>> g;
vector<int> vis, dis;

void dijk(int start){
    vis.assign(n+1, 0);
    dis.assign(n+1, 1e18);  
    priority_queue<pair<int, int>> pq;
    dis[start] = c[start];
    pq.push({-dis[start], start});
    
    while(!pq.empty()){
        int cur = pq.top().second;
        pq.pop();
        
        if(vis[cur]) continue;
        vis[cur] = 1;
        
        for(auto v : g[cur]){
            int x = v.first;
            int wt = v.second + c[x];  
            
            if(dis[x] > dis[cur] + wt){
                dis[x] = dis[cur] + wt;
                pq.push({-dis[x], x});
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    g.resize(n+1);
    c.resize(n+1);
    
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    //another way is to build graph with 
    //a---c---b
    //a----->b with cost = c+cost[b] and a<-----b with cost c+cost[a]
    //and then run dijkstra!
    dijk(1);
    
    for(int i = 1; i <= n; i++){
        cout << dis[i] << " ";
    }
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
