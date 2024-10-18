#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
string s, t;
vector<vector<vector<int>>> dp;

int rec(int l, int r, int x, int y){
    // can we match l...r of s into x...y of t
    // pruning
    if(l > r) return 0;
    if(x > y) return 0;
    
    // base case
    if(l == r && x == y) {
        return s[l] == t[x];
    }

    // cache check
    if(dp[l][r][x] != -1) return dp[l][r][x];

    // compute
    int ans = 0;
    for(int mid = l; mid < r; mid++){
        // first split of s into l...mid and mid+1...r, map to x...y of t
        if(rec(l, mid, x, x + (mid - l + 1) - 1) && rec(mid + 1, r, x + ((mid - l + 1) - 1) + 1, y)) {
            ans = 1;
        }
        // second split with reversed order
        if(rec(l, mid, (x + (r - (mid + 1) + 1) - 1) + 1, y) && rec(mid + 1, r, x, x + (r - (mid + 1) + 1) - 1)) {
            ans = 1;
        }
    }

    // save and return
    return dp[l][r][x] = ans;
}

void solve(){
    cin >> s >> t;
    n = s.length(), m = t.length();
    
    // initialize DP cache with -1 (uncomputed state)
    dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(m, -1)));
    
    if(rec(0, n-1, 0, m-1)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}
