#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
vector<vector<int>> a, dp;

int rec(int i, int j) { // max side length of square whose bottom right corner is i, j
    // pruning
    if(i < 0 || i >= n || j < 0 || j >= m) return 0;
    if(a[i][j] == 0) return 0;
    // cache check
    if(dp[i][j] != -1) return dp[i][j];
    // compute the side length of the square with bottom-right corner at (i, j)
    //min((i-1, j), (i, j-1), (i-1, j-1))
    int ans = 1 + min({rec(i-1, j), rec(i, j-1), rec(i-1, j-1)});
    // save and return
    return dp[i][j] = ans;
}

void solve() {
    cin >> n >> m;
    a.assign(n, vector<int>(m, 0));
    dp.assign(n, vector<int>(m, -1));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int maxarea = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int side = rec(i, j);
            maxarea = max(maxarea, side * side); // area = side^2
        }
    }

    cout << maxarea << endl;
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