#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
vector<vector<pair<int, int>>> g;

vector<int> vis, dis, npath, minif, maxif;

void dijk(int start){
    vis.assign(n+1, 0);
    dis.assign(n+1, 1e18);
    npath.assign(n+1, 0);
    minif.assign(n+1, 0);
    maxif.assign(n+1, 0);
    priority_queue<pair<int, int>> pq;
    dis[start] = 0;
    npath[start] = 1;
    minif[start] = 0;
    maxif[start] = 0;
    pq.push({-dis[start], start});
    while(!pq.empty()){
        int cur = pq.top().second;
        pq.pop();
        if(vis[cur]) continue;
        vis[cur] = 1;
        for(auto v : g[cur]){
            int x = v.first, wt = v.second;
            if(dis[x] > dis[cur] + wt){
                dis[x] = dis[cur] + wt;
                (npath[x] = npath[cur])%mod;
                minif[x] = minif[cur]+1;
                maxif[x] = maxif[cur]+1;
                pq.push({-dis[x], x});
            } else if(dis[x] == dis[cur] + wt){ 
                (npath[x] += npath[cur])%=mod;
                maxif[x] = max(maxif[x], maxif[cur]+1);
                minif[x] = min(minif[x], minif[cur]+1);
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    g.resize(n+1);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    dijk(1);  
    if(dis[n]==1e18){
        cout<<-1<<endl;
        return;
    }
    cout<<dis[n]<<" ";
    cout<<npath[n]%mod<<" ";
    cout<<minif[n]<<" ";
    cout<<maxif[n]<<endl;
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
