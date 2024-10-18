#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

const int N = 505;
int dp[N][N], sum[N]; 
int a[N];


//aache se dekh le kahan par mod marna hai aur kahan par NAHI!!
int get_sum(int l, int r) {
    return (sum[r]%100 - sum[l-1]%100 + 100)%100;
}

// Merge consecutive subarrays (LR DP)
int rec(int l, int r){
    //pruning: if the range is invalid, return 0
    if(l >= r) return 0;
    
    //cache check
    if(dp[l][r] != -1) return dp[l][r];
    
    //compute
    int ans = 1e18;
    
    // Try every possible partition of the subarray
    for(int k = l; k < r; k++){
        // Maximize the result by merging the two subarrays and adding their subproblems
        ans = min(ans, (get_sum(l, k) * get_sum(k+1, r)) + (rec(l, k) + rec(k+1, r)));
    }
    
    // Save the result in the dp table and return it
    return dp[l][r] = ans;
}

void printsol(int l, int r){
    // pruning
    if(l >= r){
        cout<<a[l]<<"";
        return;
    }
    //compute
    int ans = rec(l, r);
    
    for(int k = l; k < r; k++){
        if(ans==get_sum(l, k) * get_sum(k+1, r) + rec(l, k) + rec(k+1, r)){
            cout<<"(";
            printsol(l, k);
            cout<<")(";
            printsol(k+1, r);
            cout<<")";
            return;
        }   
    }
}

void solve() {
    int n;
    cin >> n;  // Input size of the array
    for(int i = 1; i <= n; i++) cin >> a[i], a[i]%=100;  // Input array elements
    
    // Build the prefix sum array
    sum[0] = 0;
    for(int i = 1; i <= n; i++) {
        sum[i] = (sum[i-1]%100 + a[i]%100)%100;
    }
    
    // Initialize the dp array with -1 (uncomputed state)
    memset(dp, -1, sizeof(dp));
    
    // Call the recursive function on the full array and print the result
    cout << rec(1, n) << "\n";
    // printsol(1, n);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
