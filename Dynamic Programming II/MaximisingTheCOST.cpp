#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

string s;
int k, m;
map<pair<int, int>, int> cost;
vector<vector<vector<int>>> dp;

int rec(int level, int kk, char prev) {
    // pruning
    if(kk < 0) return -1e18;
    // base case
    if(level == s.length()) {
        return 0;
    }
    // cache check
    if(dp[level][kk][prev - 'a'] != -1) return dp[level][kk][prev - 'a'];
    // compute
    int ans = -1e18;
    for(char c = 'a'; c <= 'z'; c++) {
        if(c != s[level]) {
            ans = max(ans, cost[{prev, c}] + rec(level + 1, kk - 1, c));
        }
        else{
            ans = max(ans, cost[{prev, c}] + rec(level + 1, kk, c));
        }
    }
    // save and return
    return dp[level][kk][prev - 'a'] = ans;
}

void solve() {
    cin >> s >> k >> m;
    cost.clear();
    dp.assign(s.length() + 1, vector<vector<int>>(k + 1, vector<int>(26, -1)));  
    for(int i = 0; i < m; i++) {
        char x, y;
        int c;
        cin >> x >> y >> c;
        cost[{x, y}] = c;
    }
    int maxi = -1e18;
    for(char c = 'a'; c <= 'z'; c++) {
        if(c != s[0]) {
            maxi = max(maxi, rec(1, k - 1, c));
        } else {
            maxi = max(maxi, rec(1, k, c));
        }
    }
    cout << maxi << endl;
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
