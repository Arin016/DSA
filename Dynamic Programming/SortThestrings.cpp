#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
vector<int> cost;
vector<string> a;
vector<vector<int>> dp;

int rec(int level, int f){ // f tells me if I had reversed the previous string or not!
    // Base case
    if(level == n) return 0;

    // Cache check
    if(dp[level][f] != -1) return dp[level][f];

    string prev = a[level - 1]; // previous string
    string cur = a[level];      // current string

    if(f == 1) reverse(prev.begin(), prev.end()); // If previous was reversed

    // Compute
    int ans = 1e18;

    // Case 1: Not reversing current string
    if(cur >= prev) {
        ans = min(ans, rec(level + 1, 0)); // Move to next without reversing
    }

    // Case 2: Reversing current string
    reverse(cur.begin(), cur.end());
    if(cur >= prev) {
        ans = min(ans, cost[level] + rec(level + 1, 1)); // Move to next after reversing
    }
    
    // Save and return
    return dp[level][f] = ans;
}

void solve() {
    cin >> n;
    a.resize(n);
    cost.resize(n);
    dp.assign(n, vector<int>(2, -1)); // dp for memoization, 2 states (reversed or not)

    for(int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Start recursion
    int ans = min(rec(1, 0), cost[0] + rec(1, 1));
    if(ans==1e18)cout<<-1<<endl;
    else cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
