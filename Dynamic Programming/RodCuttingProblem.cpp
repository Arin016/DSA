#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
vector<int> a;
vector<vector<int>> dp; // To store the memoization results

int rec(int l, int r){
    // pruning
    // base case
    if (l + 1 == r) return 0; 
    //there exists no point to break! [l, r] you need a pt in between them to make a break!

    // cache check
    if (dp[l][r] != -1) return dp[l][r];

    // compute
    int ans = 1e18;
    for (int k = l+1; k <= r-1; k++) {
        ans = min(ans, (a[r] - a[l]) + rec(l, k) + rec(k, r));
    }

    // save and return
    return dp[l][r] = ans;
}

void solve(){
    cin >> n;
    a.resize(n);
    dp.assign(n, vector<int>(n, -1)); // Initialize memoization table
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Call the recursive function
    cout << rec(0, n - 1) << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
