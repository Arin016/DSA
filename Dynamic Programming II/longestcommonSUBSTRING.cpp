#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

string a, b;
int n, m;
vector<vector<int>> dp;

//base case likhte waqt uss state ka meaning sochkar likha kar andha dun mat likh!!
int rec(int i, int j) { //max common substring len in i...n-1 and j....m-1
    // Pruning
    if(i >= n || j >= m) return 0;
    
    // Cache check
    if(dp[i][j] != -1) return dp[i][j];

    // Compute
    int ans = 0;
    ans = max(ans, 0LL);  // Skip current character in 'a'
    ans = max(ans, 0LL);  // Skip current character in 'b'
    
    if(a[i] == b[j]) {  // If characters match, add 1 and move both pointers
        ans = max(ans, 1 + rec(i + 1, j + 1));
    }
    
    // Save and return the result
    return dp[i][j] = ans;
}


void solve() {
    cin >> a >> b;
    n = a.length(), m = b.length();
    
    // Initialize dp table with -1
    dp = vector<vector<int>>(n, vector<int>(m, -1));
    
    // Output the length of the longest common substring
    int maxi = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            maxi = max(maxi, rec(i, j));
        }
    }
    cout << maxi << endl;
    //agar solution print karna hai toh pehle optimal start indices pakad kar la and then uss
    //par printsol call karna just as we did in the case of LIS ka soln printing!
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
