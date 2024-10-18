#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
string s, t;
vector<vector<int>> pre, dp;

int rec(int i, int j){ // shortest uncommon subsequence from s[i...n] in t[j....m]
    // Pruning step
    if(i == n){ // If we've exhausted all characters in 's'
        return 1e18; // No subsequence can be formed, return a large value indicating invalid state.
    }
    if(j == m){ // If we've exhausted all characters in 't'
        return 1; // The shortest uncommon subsequence is the current character from 's', as 't' is empty.
    }
    
    // cache check
    if(dp[i][j] != -1) return dp[i][j];
    //compute
    int ans = 1e18; // Initialize answer with a large value
    //lene ko mat dekh!!
    //'s[i]' is not included in the shortest uncommon subsequence
    ans = min(ans, rec(i + 1, j));
    //lene ko dekh!!
    //If 's[i]' is not found in 't[j...m]', i.e., no occurrence of 's[i]' exists beyond index 'j' in 't'
    if(pre[i][j] == m){
        ans = 1; // The shortest uncommon subsequence is just 's[i]' because it doesn't appear in 't[j...m]'
    }
    else{
        //'s[i]' is included in the shortest uncommon subsequence
        ans = min(ans, 1 + rec(i + 1, pre[i][j] + 1));
    }

    // save and return
    return dp[i][j] = ans;
}

void solve(){
    cin >> s >> t;
    n = s.length(), m = t.length();
    pre.assign(n+1, vector<int>(m+1, 0));
    dp.assign(n+1, vector<int>(m+1, -1)); // Initialize dp with -1 for memoization

    // pre[i][j] = tells us when was the nearest forward we saw s[i] in t when at index j in t
    for(int i = 0; i < n; i++){
        int idx = m;
        for(int j = m-1; j >= 0; j--){
            if(s[i] == t[j]){
                idx = j;
            }
            pre[i][j] = idx;
        }
    }

    if(rec(0, 0) == 1e18) cout << -1 << endl;
    else cout << rec(0, 0) << endl;
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
