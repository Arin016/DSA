#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
vector<double> p;
vector<vector<double>> dp; 

// dp[i][H] stores the probability of getting more heads than tails in the subarray [i...n]
double rec(int i, int H){
    // Pruning
    // Base case: If we have processed all coins
    if(i == n){
        // If heads are more than half return 1 (valid), else 0
        return H >= (n+1)/2;
    }
    
    // Cache check: Return the cached result if already computed
    if(dp[i][H] != -1) return dp[i][H];
    
    // Compute: Add the probabilities of choosing head or tail
    double ans = 0;
    
    // Option 1: Take the head for the current coin, decrement H
    ans += (p[i]) * rec(i+1, H+1);
    
    // Option 2: Take the tail for the current coin, H remains the same
    ans += (1 - p[i]) * rec(i+1, H);
    
    // Save and return the computed result
    return dp[i][H] = ans;
}

void solve(){
    cin >> n;
    p.resize(n);
    
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    dp.resize(n, vector<double>(n+1, -1));

    cout << setprecision(10) << rec(0, 0) << endl;
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
