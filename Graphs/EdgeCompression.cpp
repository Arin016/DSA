#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<vector<pair<int,int>>> g;
vector<int> vis;
vector<int> dis;
int n, a, b;

void dijkstra(int sc){
    vis.assign(2*n+2,0);
    dis.assign(2*n+2,1e18);

    priority_queue<pair<int,int>> pq;
    dis[sc] = 0;
    pq.push({-0,sc});

    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();

        int cur_node = x.second;
        int cur_weight = -x.first;

        if(vis[cur_node]==1){
            continue;
        }else{
            vis[cur_node] = 1;
        }

        for(auto v:g[cur_node]){
            int neigh = v.first;
            int weight = v.second;
            if(dis[neigh]>dis[cur_node]+weight){
                dis[neigh] = dis[cur_node]+weight;
                pq.push({-dis[neigh],neigh});
            }
        }
    }
}

void solve(){
    cin>>n>>a>>b;
    //a cost to adjacent node and b cost to same element
    map<int,vector<int>> mp;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        mp[x].push_back(i);
    }
    g.resize(n+mp.size()+1);
    for(int i=1;i<n;i++){
        g[i].push_back({i+1,b});
        g[i+1].push_back({i,b});
    }
    int Dnode = n+1;
    for(auto &v:mp){
        for(auto u:v.second){
            g[u].push_back({Dnode,0});
            g[Dnode].push_back({u,a});
        }
        Dnode++;
    }  

    int sc;
    cin>>sc;
    dijkstra(sc);
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    cout<<endl; 
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}