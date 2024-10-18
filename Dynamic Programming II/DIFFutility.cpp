//if you consider the "-" youll get first string, if you consider "+" youll get second one
//x = XMJYAUZ
//y = XMJAATZ

//compute the smallest diff utility string

#include<bits/stdc++.h>
using namespace std;
#define int long long
//this idea is used multiple times!!!!
//#####
//first calculate the length of the diff utility string and then backtrack and get the solution!
//####
int mod = 1e9+7;
string x, y;
int n, m;
vector<vector<int>> dp;  // DP cache

// Function to compute the smallest diff utility string
int rec(int i, int j) {
    // Pruning
    if(i==n and j==m)return 0;
    //base case
    if (i == n) return m - j;  // Remaining characters in y
    if (j == m) return n - i;  // Remaining characters in x
    
    // Cache check
    if (dp[i][j] != -1) return dp[i][j];
    
    // Compute
    int ans = 1e18;
    ans = min(ans, 1 + rec(i + 1, j));  // Delete from x
    ans = min(ans, 1 + rec(i, j + 1));  // Delete from y
    
    if (x[i] == y[j]) {  // If characters match, move both pointers
        ans = min(ans, 1 + rec(i + 1, j + 1));
    }
    
    // Save and return 
    return dp[i][j] = ans;
}

void printsol(int i, int j) {
    if (i == n and j == m) return;
    //writing these two were necessary!!!!
    if(i<n and j==m){
        cout<<"-"<<x[i]<<" ";
        printsol(i + 1, j);
        return;
    }
    if(j<m and i==n){
        cout<<"+"<<y[j]<<" ";
        printsol(i, j + 1);
        return;
    }
    int ans = rec(i, j);
    if(ans==1+rec(i+1, j)){
        cout<<"-"<<x[i]<<" ";
        printsol(i + 1, j);
        return;
    }
    else if(ans==1+rec(i, j+1)){
        cout<<"+"<<y[j]<<" ";
        printsol(i, j + 1);
        return;
    }
    if(x[i]==y[j]){
        if(ans==1+rec(i+1, j+1)){
            cout<<x[i]<<" ";
            printsol(i + 1, j + 1);
            return;
        }
    }
}

void solve() {
    cin >> x >> y;
    n = x.length(), m = y.length();
    dp.assign(n, vector<int>(m, -1));  // Initialize DP cache
    cout << rec(0, 0) << endl;
    printsol(0, 0);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
