#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
vector<pair<pair<int, int>, int>> edges;
vector<int> dis;

void solve(){
    cin>>n>>m;
    dis.assign(n+1, 1e18);
    for(int i=0;i<m;i++){
        int x, y, w;
        cin>>x>>y>>w;
        edges.push_back({{x, y}, -w});
    }
    bool flag = false;
    dis[1] = 0;
    for(int i=0;i<n;i++){ //n-1 + 1 times relaxation of all edges!
        for(auto x:edges){
            int u = x.first.first, v = x.first.second;
            int wt = x.second;
            if(dis[v]>dis[u]+wt){
                if(i==n-1)flag = true;
                dis[v] = dis[u]+wt;
            }
        }
    }
    if(flag)cout<<-1<<endl;
    else cout<<-dis[n]<<endl;
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
