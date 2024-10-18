#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
string s;
vector<int> dp2;
vector<vector<int>> dp1;

// Function to check if a substring s[l...r] is a palindrome
int ispalindrome(int l, int r){
    // pruning
    // base case
    if(l >= r) return 1; // either empty string l>r or one char l==r
    
    // cache check
    if(dp1[l][r] != -1) return dp1[l][r];
    
    // compute
    int ans = 1;
    if(s[l] == s[r]){
        ans &= ispalindrome(l + 1, r - 1);
    }
    else ans = 0;
    
    // save and return
    return dp1[l][r] = ans;
}

// Recursive function to find the minimum cuts needed for palindrome partitioning
int rec(int level){
    // pruning
    if(level > n) return 1e18;
    
    // base case
    if(level == n) return 0;
    
    // cache check
    if(dp2[level] != -1) return dp2[level];
    
    // compute
    int ans = 1e18;
    for(int i = level; i < n; i++){
        if(ispalindrome(level, i)){
            ans = min(ans, 1 + rec(i + 1));
        }
    }
    
    // save and return
    return dp2[level] = ans;
}

void printsol(int level) {
    // pruning
    if (level > n) return;

    // base case
    if (level == n) return;

    // compute
    int ans = rec(level);
    for (int i = level; i < n; i++) {
        if (ispalindrome(level, i)) {
            // If current partition is part of the optimal solution
            if (ans == 1 + rec(i + 1)) {
                cout << s.substr(level, i - level + 1) << " ";
                printsol(i + 1);
                return;
            }
        }
    }
}


void solve(){
    cin >> s;
    n = s.size();
    
    // Reset the dp caches for each test case
    dp1.assign(n + 1, vector<int>(n + 1, -1));  // cache for palindrome check
    dp2.assign(n + 1, -1);  // cache for recursion
    
    // Output the minimum cuts for the current string
    cout << rec(0) << '\n';
    printsol(0);
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
