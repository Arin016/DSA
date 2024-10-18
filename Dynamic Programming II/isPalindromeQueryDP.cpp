#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

string s;
vector<vector<int>> dp;

//couldve used manacher / string hashing too!!

int rec(int l, int r){
    // pruning
    // base case
    if(l >= r) return 1; // either empty string l>r or one char l==r
    
    // cache check
    if(dp[l][r] != -1) return dp[l][r];
    
    // compute
    int ans = 1;
    if(s[l] == s[r]){
        ans &= rec(l + 1, r - 1);
    }
    else ans = 0;
    
    // save and return
    return dp[l][r] = ans;
}

void solve(){
    cin >> s;
    int n = s.size();
    dp.assign(n, vector<int>(n, -1));  // reset the dp cache for each test case
    int isPalindrome = rec(0, n - 1);
    cout << (isPalindrome ? "YES" : "NO") << "\n";
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
