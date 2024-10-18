#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
vector<vector<int>> a, dp;

int rec(int i, int j){ 
    //min health required to go from i, j to n-1, m-1 without health dropping to 0 or below
    // Base case
    if(i >= n || j >= m) return 1e18;  // Out of bounds, return large value to indicate invalid path
    
    // If we are at the bottom-right corner (the exit), we need at least 1 health to survive
    if(i == n-1 && j == m-1) {
        if(a[i][j] < 0) return 1 + abs(a[i][j]);  // If there's a negative health penalty, adjust
        else return 1;  // If it's 0 or positive, Gerald just needs 1 health to exit
    }
    
    // If the value is already computed, use the cached result
    if(dp[i][j] != -1) return dp[i][j];
    
    // Recursive calls to calculate the minimum health needed to move right or down
    int right = rec(i, j + 1);
    int down = rec(i + 1, j);
    
    // Calculate the minimum health needed after moving either right or down
    int needed_health = min(right, down) - a[i][j];
    
    // The health must be at least 1 at all times
    return dp[i][j] = max(1LL, needed_health);
}

void solve() {
    cin >> n >> m;
    a.assign(n, vector<int>(m));
    dp.assign(n, vector<int>(m, -1));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
    // Start from the top-left corner and compute the minimum initial health required
    cout << rec(0, 0) << endl;
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
