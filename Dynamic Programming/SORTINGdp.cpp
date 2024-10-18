#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;

int n, a, b;
vector<pair<int, int>> arr;
vector<vector<int>> dp; // 3D DP cache (level, nb)

int rec(int level, int na, int nb) {
    // Pruning
    if (na < 0 || nb < 0) return -1e18;

    // Base case
    if (level == n) {
        if (na == 0 && nb == 0) return 0;
        else return -1e18;
    }

    // Cache check
    if (dp[level][nb] != -1) return dp[level][nb];

    // Compute
    int ans = -1e18;
    //jab tak a mein lene ka jagah hai mein skip nhai karunga a mein dal dunga
    // Put it in team A if posible nahi toh skip!
    if(na>0){
        ans = max(ans, arr[level].first + rec(level + 1, na - 1, nb));
    }
    else ans = max(ans, rec(level + 1, na, nb));
    // Put it in team B
    ans = max(ans, arr[level].second + rec(level + 1, na, nb - 1));

    // Save and return
    return dp[level][nb] = ans;
}

void solve() {
    cin >> n >> a >> b;
    arr.resize(n);
    
    // Initialize DP with -1 (uncomputed state)
    dp.assign(n + 1, vector<int>(b + 1, -1));
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    // Sorting based on A's values to force transitions into team A
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    int result = rec(0, a, b);
    if (result < 0) result = -1; // Return -1 if no valid configuration exists
    cout << result << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
