#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

//dp(node, 1) --> i dont want to include the edge(parent---node) thus i want to choose best k edges in (node----child)
//dp(node, 0) --> i want to choose the edge(parent--node) thus i want to choose best k-1 edges in (node---child)
//ans = max(dp(1, 1), dp(1, 0))

int n, k;
vector<vector<pair<int, int>>> g;
vector<vector<int>> dp;
void dfs(int node, int par){
    //if node were a leaf
    dp[node][1] = 0;
    dp[node][0] = 0;
    vector<int> delta;
    int base = 0;
    //
    for(auto x:g[node]){
        if(x.first!=par){
            dfs(x.first, node);
            base += dp[x.first][1]; //initailly assuming i havent taken the (node---x) edge
            delta.push_back(-dp[x.first][1]+(x.second)+dp[x.first][0]);
        }
    }
    //
    sort(delta.begin(), delta.end());
    delta.push_back(0); //if i chose not to convert any of the childs to dp(child, 0)
    reverse(delta.begin(), delta.end());
    //0 sits at the begining of the delta vector, the choice of not converting any child
    for(int ch=0;ch<(int)delta.size();ch++){
        base+=delta[ch];
        if(ch<=k){
            dp[node][1] = max(dp[node][1], base);
        }
        if(ch<=k-1){
            dp[node][0] = max(dp[node][0], base);
        }
    }
}

void solve(){
    cin >> n >> k;
    g.clear();
    g.resize(n+1);
    dp.clear();
    dp.assign(n+1, vector<int>(2, 0));
    for(int i = 0; i < n-1; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << endl;

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
