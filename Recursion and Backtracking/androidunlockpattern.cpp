#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int MAX_N = 15;

int n;
bool visited[10];
int pre[10][10];

// 1 2 3
// 4 5 6
// 7 8 9

int rec(int cur, int level) {
    // Base case
    if (level == n) {
        return 1;
    }
    // Compute
    int ans = 0;
    // Recursive case
    for (int i = 1; i <= 9; i++) {
        if (!visited[i] && ((pre[cur][i] == 0) || visited[pre[cur][i]])) {
            visited[i] = true;
            ans += rec(i, level + 1);
            visited[i] = false;
        }
    }
    return ans; 
}

void solve() {
    cin >> n;
    int ans = 0;
    memset(visited, 0, sizeof(visited));
    memset(pre, 0, sizeof(pre));
    
    pre[1][3] = pre[3][1] = 2;
    pre[1][7] = pre[7][1] = 4;
    pre[7][9] = pre[9][7] = 8;
    pre[9][3] = pre[3][9] = 6;

    pre[1][9] = pre[9][1] = 5;
    pre[2][8] = pre[8][2] = 5;
    pre[3][7] = pre[7][3] = 5;
    pre[4][6] = pre[6][4] = 5;

    visited[1] = true;
    ans += rec(1, 1) * 4;
    visited[1] = false;

    visited[2] = true;
    ans += rec(2, 1) * 4;
    visited[2] = false;

    visited[5] = true;
    ans += rec(5, 1);
    visited[5] = false;

    cout << ans << endl;
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
    return 0;
}
