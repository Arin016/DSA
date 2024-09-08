#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9+7;

//dp[i][x] = no of nodes in this subtree at distance x
//tree distance in AZ
int n, k;
vector<vector<int>> g, dp;
int ans;

void dfs(int node, int par){
    dp[node][0] = 1;
    for(auto x : g[node]){
        if(x != par){
            dfs(x, node);
            for(int dis = 1; dis <= k; dis++){
                //in the computed child(x) i want number of nodes at a distance dis-1 as that would 
                //be equal to a distance of dis from node
                ans += ((dp[node][k-dis] * dp[x][dis-1]));
            }
            for(int dis = 1; dis <= k; dis++){
                dp[node][dis] += dp[x][dis-1];
            }
        }
    }
}

void solve(){
    cin >> n >> k;
    g.clear();
    dp.clear();
    g.resize(n+1);
    dp.assign(n+1, vector<int>(k+1, 0));
    ans = 0;

    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
