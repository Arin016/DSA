#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m, k;
vector<vector<int>> dp;

int rec(int level, int kk){
    // Pruning
    if (kk < 0) return 0;

    // Base case
    if (level == n) {
        return kk == 0;
    }
    //cache check
    if(dp[level][kk]!=-1){
        return dp[level][kk];
    }

    // Compute
    int ans = 0;
    ans += (m - 1) * rec(level + 1, kk - 1);
    ans +=rec(level + 1, kk);

    // Return result
    return dp[level][kk] = ans;
}

void solve() {
    cin >> n >> m >> k;
    dp.assign(n+1, vector<int>(k+1, -1));
    cout << (m * rec(1, k)) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
