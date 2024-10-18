#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
vector<vector<int>> a, dp, done;

//if the values are -ve in a then use a bool done array to check if the state is computed along with dp that
//stores the ans for the state!!

int rec(int i, int j){ //max path sum form (i, j ....... n-1, m-1)!
    // Pruning
    if(i < 0 || i >= n || j < 0 || j >= m) return -1e18;

    // Base case
    if(i == n-1 && j == m-1) return a[i][j];

    // Cache check
    if(done[i][j]) return dp[i][j];

    // Compute
    int ans = -1e18;
    ans = max(ans, a[i][j] + rec(i+1, j));
    ans = max(ans, a[i][j] + rec(i, j+1));

    // Save and return
    done[i][j] = 1;
    return dp[i][j] = ans;
}

void solve() {
    cin >> n >> m;
    a.resize(n, vector<int>(m));
    dp.assign(n, vector<int>(m, -1));
    done.assign(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Call the recursive function and print the result
    cout << rec(0, 0) << endl;
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
