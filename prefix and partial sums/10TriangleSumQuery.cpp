#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
typedef pair<int, int> pii;
typedef pair<long, long> pll;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> arr(n, vector<int>(m, 0));
    vector<vector<int>> triangular_prefix_sum(n, vector<int>(m, 0));
    vector<vector<int>> rect_prefix_sum(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            arr[i][j] = (arr[i][j] + mod) % mod;
        }
    }

    // Calculate triangular prefix sum
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            triangular_prefix_sum[i][j] = arr[i][j];
            if (i > 0 && j > 0) {
                triangular_prefix_sum[i][j] = (triangular_prefix_sum[i][j] + triangular_prefix_sum[i-1][j-1]) % mod;
            }
            if (i > 0) {
                triangular_prefix_sum[i][j] = (triangular_prefix_sum[i][j] + triangular_prefix_sum[i-1][j]) % mod;
            }
            if (i >= 2 && j > 0) {
                triangular_prefix_sum[i][j] = (triangular_prefix_sum[i][j] - triangular_prefix_sum[i-2][j-1] + mod) % mod;
            }
        }
    }

    // Calculate rectangular prefix sum
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            rect_prefix_sum[i][j] = arr[i][j];
            if (i > 0) {
                rect_prefix_sum[i][j] = (rect_prefix_sum[i][j] + rect_prefix_sum[i-1][j]) % mod;
            }
            if (j > 0) {
                rect_prefix_sum[i][j] = (rect_prefix_sum[i][j] + rect_prefix_sum[i][j-1]) % mod;
            }
            if (i > 0 && j > 0) {
                rect_prefix_sum[i][j] = (rect_prefix_sum[i][j] - rect_prefix_sum[i-1][j-1] + mod) % mod;
            }
        }
    }

    while (q--) {
        int x, y, l;
        cin >> x >> y >> l;
        x--; y--; 

        int ans = triangular_prefix_sum[x][y] % mod;

        if (x >= l && y >= l) {
            ans = (ans - triangular_prefix_sum[x-l][y-l] + mod) % mod;
        }
        if (x >= l) {
            ans = (ans - rect_prefix_sum[x-l][y] + mod) % mod;
        }
        if (x >= l && y >= l) {
            ans = (ans + rect_prefix_sum[x-l][y-l]) % mod;
        }

        cout << ans << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}