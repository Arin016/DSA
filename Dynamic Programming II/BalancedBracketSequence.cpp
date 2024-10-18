#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
string s;
vector<vector<int>> dp;

int rec(int level, int depth){
    // pruning
    if(depth < 0) return 0;
    
    // base case
    if(level == n) return depth == 0;
    
    // cache check
    if(dp[level][depth] != -1) return dp[level][depth];
    
    // compute
    int ans = 0;
    if(s[level] == '?'){
        ans = (rec(level+1, depth+1) + rec(level+1, depth-1)) % mod;
    }
    else {
        if(s[level] == '('){
            ans = rec(level+1, depth+1) % mod;
        } else {
            ans = rec(level+1, depth-1) % mod;
        }
    }
    
    // save and return
    return dp[level][depth] = ans % mod;
}

void solve(){
    cin >> s;
    n = s.size();
    dp = vector<vector<int>>(n+1, vector<int>(n+1, -1));
    cout << rec(0, 0) << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
