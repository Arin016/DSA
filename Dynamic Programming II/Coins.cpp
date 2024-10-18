#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
vector<double> p;
vector<vector<double>> dp; // DP table to store results of subproblems

// dp[i][H] stores the probability of getting H heads in the subarray [i...n]
double rec(int i, int H){
    // Pruning: If heads (H) become negative, it's invalid, return 0 probability
    if(H < 0) return 0;
    
    // Base case: If we have processed all coins
    if(i == n){
        // If exactly H heads are required and H is 0, return 1 (valid), else 0
        return H == 0;
    }
    
    // Cache check: Return the cached result if already computed
    if(dp[i][H] != -1) return dp[i][H];
    
    // Compute: Add the probabilities of choosing head or tail
    double ans = 0;
    
    // Option 1: Take the head for the current coin, decrement H
    ans += (p[i]) * rec(i+1, H-1);
    
    // Option 2: Take the tail for the current coin, H remains the same
    ans += (1 - p[i]) * rec(i+1, H);
    
    // Save and return the computed result
    return dp[i][H] = ans;
}

void solve(){
    cin >> n;
    p.resize(n); // Resizing vector p to store probabilities for n coins
    
    // Read the probability for each coin to be head
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    
    // Resizing dp table to n rows and n+1 columns (H can range from 0 to n)
    dp.resize(n, vector<double>(n+1, -1));
    
    double fans = 0; // To store the final answer
    
    // Summing the probabilities of getting more than n/2 heads
    for(int H = n/2 + 1; H <= n; H++){
        fans += rec(0, H);
    }
    
    // Output the final answer with precision
    cout << setprecision(10) << fans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}
