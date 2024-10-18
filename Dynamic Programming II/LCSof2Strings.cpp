#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

string a, b;
int n, m;
vector<vector<int>> dp;

//base case likhte waqt uss state ka meaning sochkar likha kar andha dun mat likh!!
int rec(int i, int j) {
    // Pruning
    if(i == n || j == m) return 0;
    
    // Cache check
    if(dp[i][j] != -1) return dp[i][j];

    // Compute
    int ans = 0;
    ans = max(ans, rec(i + 1, j));  // Skip current character in 'a'
    ans = max(ans, rec(i, j + 1));  // Skip current character in 'b'
    
    if(a[i] == b[j]) {  // If characters match, add 1 and move both pointers
        ans = max(ans, 1 + rec(i + 1, j + 1));
    }
    
    // Save and return the result
    return dp[i][j] = ans;
}

void printsol(int i, int j) {
    // Pruning
    if (i == n || j == m) return;
    //base case
    // compute
    int ans = rec(i, j);
    
    // Catch the right transition
    if (ans == rec(i + 1, j)) {
        printsol(i + 1, j);
        return;
    } else if (ans == rec(i, j + 1)) {
        printsol(i, j + 1);
        return;
    }
    
    if (a[i] == b[j]) {
        if (ans == 1 + rec(i + 1, j + 1)) {
            cout << a[i];  // Output the common character
            printsol(i + 1, j + 1);
            return;
        }
    }    
}

void solve() {
    cin >> a >> b;
    n = a.length(), m = b.length();
    
    // Initialize dp table with -1
    dp = vector<vector<int>>(n, vector<int>(m, -1));
    
    // Output the length of the longest common subsequence
    // cout << rec(0, 0) << endl;
    
    // Print the actual subsequence
    printsol(0, 0);
    cout << endl;
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
