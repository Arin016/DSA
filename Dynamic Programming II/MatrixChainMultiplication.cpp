#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
vector<int> x, y; // dimensions of matrices (x[i] * y[i])
vector<vector<int>> dp; 

// Recursive function to compute minimum number of operations
int rec(int l, int r) {
    // Base case: single matrix, no multiplication needed
    if (l == r) return 0;

    // Cache check
    if (dp[l][r] != -1) return dp[l][r];

    //compute
    int ans = 1e18;

    // Compute minimum operations by splitting at k
    for (int k = l; k <= r - 1; k++) { // [l...k...r]
        ans = min(ans, x[l] * y[k] * y[r] + rec(l, k) + rec(k + 1, r));
    }

    // Save and return 
    return dp[l][r] = ans;
}

void printsol(int l, int r) {
    // Base case: single matrix, no multiplication needed
    if (l == r) {
        cout << "M" << l + 1; // Output matrix name (A1, A2, etc.)
        return;
    }

    // Retrieve the optimal split point for the range [l, r]
    int ans = rec(l, r);

    // Find the optimal split `k`
    for (int k = l; k <= r - 1; k++) {
        if (ans == x[l] * y[k] * y[r] + rec(l, k) + rec(k + 1, r)) {
            cout << "(";
            // Recur for the left part [l, k]
            printsol(l, k);
            cout << ")(";
            // Recur for the right part [k + 1, r]
            printsol(k + 1, r);
            cout << ")";
            return;
        }
    }
}


void solve() {
    cin >> n;
    x.resize(n + 1);
    y.resize(n + 1);
    
    // Input matrix dimensions
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    x[n] = y[n - 1]; // Adjust x[n] based on the last matrix's dimension

    // Initialize DP table with -1 (uncomputed)
    dp.assign(n + 1, vector<int>(n + 1, -1));
    cout << rec(0, n - 1) << '\n';
    printsol(0, n-1);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
