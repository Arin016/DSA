#include<bits/stdc++.h>
using namespace std;
#define int int64_t
const int MOD = 1e9+7;

int n, m;
vector<vector<int>> g;
vector<int> dp, in_degree;

void solve() {
    cin >> n >> m;
    g.assign(n + 1, vector<int>());
    in_degree.assign(n + 1, 0);
    dp.assign(n + 1, 0);
    
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        in_degree[y]++;
    }
    
    queue<int> q;
    dp[1] = 1;  // There's exactly one way to start at level 1
    
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (auto x : g[node]) {
            dp[x] = (dp[x] + dp[node]) % MOD;
            if (--in_degree[x] == 0) {
                q.push(x);
            }
        }
    }
    
    // Output the number of ways to reach level n
    cout << dp[n] << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
