#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
vector<int> a;
vector<int> cnt, dp;
//cnt[i] holds the number of longest increasing subsequences that end at index i.

int rec(int level) { // LIS starting at level
    // base case
    if (level == n) return 0;

    // cache check
    if (dp[level] != -1) return dp[level];

    // compute
    int ans = 1;
    cnt[level] = 1;  // minimum number of LIS starting at level
    for (int i = level + 1; i < n; i++) {
        if (a[level] < a[i]) { //if i find an a[i] > a[level]
            if (ans < 1 + rec(i)) { //if inclusion of i gives me a better LIS
                ans = 1 + rec(i);
                cnt[level] = cnt[i];  //then no of lis at level would be equal to no of lis at i
            }
            else if (ans == 1 + rec(i)) { //if i find another such i, i add it to the cnt[level]
                cnt[level] = (cnt[level] + cnt[i]) % mod;
                // if i find an a[i] > a[level] and [ans==1+rec(i)] then no of lis at level would be equal to no of lis at i
            }
        }
    }

    // save and return
    return dp[level] = ans;
}

void solve() {
    cin >> n;
    a.resize(n);
    cnt.assign(n, 0);
    dp.assign(n, -1);

    for (int i = 0; i < n; i++) cin >> a[i];

    int LIS = -1;
    int ans = 0;

    // calculate LIS for each element
    for (int i = 0; i < n; i++) {
        if (LIS < rec(i)) {
            LIS = rec(i);
            ans = cnt[i];  // update the count
        }
        else if (LIS == rec(i)) {
            ans = (ans + cnt[i]) % mod;  // accumulate the count
        }
    }

    cout << ans << endl;
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
