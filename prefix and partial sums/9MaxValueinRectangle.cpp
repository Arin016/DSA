#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    
    // Initialize the 2D array and the difference array
    int p[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            p[i][j] = 0;
        }
    }
    
    // Process each query
    while (q--) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        x1--, y1--, x2--, y2--; // Convert to 0-based indexing

        p[x1][y1] += c;
        if (y2 + 1 < m) p[x1][y2 + 1] -= c;
        if (x2 + 1 < n) p[x2 + 1][y1] -= c;
        if (x2 + 1 < n && y2 + 1 < m) p[x2 + 1][y2 + 1] += c;
    }
    
    // Apply the 2D prefix sum to calculate the final array
    int max_val = -1e18, max_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0) p[i][j] += p[i - 1][j];
            if (j > 0) p[i][j] += p[i][j - 1];
            if (i > 0 && j > 0) p[i][j] -= p[i - 1][j - 1];

            // Check for maximum value and its count
            if (p[i][j] > max_val) {
                max_val = p[i][j];
                max_count = 1;
            } else if (p[i][j] == max_val) {
                max_count++;
            }
        }
    }
    
    // Output the result
    cout << max_val << " " << max_count << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
