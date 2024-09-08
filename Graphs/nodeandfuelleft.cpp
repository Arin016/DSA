#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
const int N = 1e4+100;
const int NN = 1e2+100;

int n, m, k;
vector<int> c;
vector<vector<pair<int, pair<int, int>>>> g;
vector<vector<int>> vis, dis;

void dijk(int node, int fuelleft){
    vis.assign(N, vector<int>(NN, 0));
    dis.assign(N, vector<int>(NN, 1e18));
    //this helps us to tell the order in which edges must be relaxed so that each edge is relaxed once, (ONCE)???, yes once!
    priority_queue<pair<int, pair<int, int>>> pq; //we keep (-dis, ""stateconfig"") in pq!!!!
    dis[node][fuelleft] = 0;
    pq.push({-dis[node][fuelleft], {node, fuelleft}});
    while(!pq.empty()){
        auto cur = pq.top().second; //cur state!
        pq.pop();
        if(vis[cur.first][cur.second])continue;
        vis[cur.first][cur.second] = 1;

        //refill : (node, fuelleft) ---C[node]---> (node, fuelleft+1)
        if(cur.second<k){ //fuelleft<k
            if(dis[cur.first][cur.second+1]>dis[cur.first][cur.second]+c[cur.first]){
                dis[cur.first][cur.second+1] = dis[cur.first][cur.second]+c[cur.first];
                pq.push({-dis[cur.first][cur.second+1], {cur.first, cur.second+1}});
            }
        }
        
        //try and go to neighbour : (node, fuelleft) ---0---> (neigh, fuelleft-Pi)
        for(auto x:g[cur.first]){
            if(cur.second>=x.second.first){ //fuelleft-Pi>=0
                if(dis[x.first][cur.second-x.second.first]>dis[cur.first][cur.second]+(0)){
                    dis[x.first][cur.second-x.second.first] = dis[cur.first][cur.second]+(0);
                    pq.push({-dis[x.first][cur.second-x.second.first], {x.first, cur.second-x.second.first}});
                }
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    c.resize(n+1);
    for(int i=0;i<m;i++){
        int a, b, P, D;
        cin>>a>>b>>P;
        D = P;
        g[a].push_back({b, {P, D}});
        g[b].push_back({a, {P, D}});
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    int st, en;
    cin>>st>>en>>k;
    dijk(st, 0);
    cout<<dis[en][0]<<endl;
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
