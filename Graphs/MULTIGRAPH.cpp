#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


int n, m;
vector<vector<int>> g; 
vector<int> vis, par;
bool iscycle;

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    iscycle = false;
    vis.assign(n+1, 1);
    par.assign(n+1, -1);
    map<pair<int, int>, int> mp;
    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        if(x==y){
            //self loop
            continue;
        }
        if(x>y)swap(x, y);
        mp[{x, y}]++;
        if(mp[{x, y}]>1){
            //multi edge
            continue;
        }
        g[x].push_back(y); 
        g[y].push_back(x);
    }
    
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
