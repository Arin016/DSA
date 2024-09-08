#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
vector<vector<int>> g;
vector<int> parent;
vector<int> val, ans;

void dfs(int node, int par, int mini, int maxi){
    parent[node] = par;
    ans[node] = max(abs(val[node]-mini), abs(val[node]-maxi));
    for(auto x:g[node]){
        if(x!=par){
            dfs(x, node, min(mini, val[node]), max(maxi, val[node]));
        }
    }
}

void solve(){
    cin>>n;
    g.resize(n+1);
    parent.resize(n+1);
    ans.resize(n+1);
    val.resize(n+1);
    for(int i=0;i<n-1;i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=0;i<n;i++){
        cin>>val[i];
    }

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
