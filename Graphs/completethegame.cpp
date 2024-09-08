// //undirected hota toh in out dp!
// int rec(int node){ //longest path starting at node in ""directed graph""!!
//     //base case
//     if(g[node].empty()){ // if no outgoing edges
//         return 1;
//     }
//     //cache check
//     if(dp[node] != -1) return dp[node];
//     //compute
//     int ans = 0;
//     for(auto x : g[node]){
//         ans = max(ans, 1 + rec(x));
//     }
//     //save and return
//     return dp[node] = ans;
// }

#include<bits/stdc++.h>
using namespace std;
#define int int64_t

int mod = 1e9+7;

int n, m;
vector<vector<int>> g;
vector<int> dp;

int rec(int node){
    //base case
    if(node==n) return 1;
    //cache check
    if(dp[node]!=-1) return dp[node];
    //compute
    int ans=0;
    for(auto it:g[node]){
        ans=(ans+rec(it))%mod;
    }
    //save and return
    return dp[node]=ans;
}

void solve() {
    cin >> n >> m;
    g.assign(n + 1, vector<int>()); 
    dp.assign(n+1, -1);
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    cout<<rec(1)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
}
