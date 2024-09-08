#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


// dp(node, takethis/nottakethis, x) --> maximum value out of subtree with "exactly" x nodes pickings and with
// node being picked/notpicked
// ans = max(dp(1, 1, k), dp(1, 0, k))
int n, k;
int val[101];
int subtreesz[101];
int dp[101][2][101];
vector<int> g[101];

void dfs(int node, int par) {
    // initialise the value of dp as if they were leaf
    for(int i = 0; i <= n; i++) {
        dp[node][1][i] = (i == 1 ? val[node] : -1e9);
        dp[node][0][i] = (i == 0 ? 0 : -1e9);
    }
    subtreesz[node] = 1;
    //
    for(auto x : g[node]) {
        if(x != par) {
            dfs(x, node); // itna call karte hi saare values as if leaf set hojayenge
            // abb wapas aate waqt saare sahi values calculate karke rakh ke aana hai
            // from x child we are taking b nodes
            // and a # of nodes has been taken from other childs till now
            for(int a = subtreesz[node]; a >= 0; a--) {
                for(int b = subtreesz[x]; b >= 0; b--) {
                    dp[node][0][a + b] = max(dp[node][0][a + b], dp[node][0][a] + max(dp[x][1][b], dp[x][0][b]));
                    dp[node][1][a + b] = max(dp[node][1][a + b], dp[node][1][a] + dp[x][0][b]);
                }
            }
            subtreesz[node] += subtreesz[x];
        }
    }
    //
}

void solve() {
    cin >> n >> k;
    for(int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    cout << max(dp[1][0][k], dp[1][1][k]) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}

// assuming node only had 2 child->(a, b)
// dp(node, 1, x) = val[node] + max_across_all_y(dp(a, 0, y) + dp(b, 0, x-1-y))
// dp(node, 0, x) = take/nottake a and take/nottake b 
// and how many nodes to pick from each of them ?? run a loop in y same as above case
// = max_across_all_y(max(dp(a, 0, y), dp(a, 1, y)) + max(dp(b, 0, x-y), dp(b, 1, x-y)))

// but child are not two and can be many!

// dp2(childi, X) --> maximum value you can obtain in childi......childm with atmost X nodes to pick
