#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, k;
vector<int> a;
vector<int> dp; // to store minimum cost from each level

int rec(int level){ 
    // Pruning
    if(level > n) return 1e18;
    
    // Base case
    if(level == n) return 0; //min cost to recah from n...n is 0!
    
    // Cache check
    if(dp[level] != -1) return dp[level];
    
    // Compute
    int ans = 1e18;
    for(int i = level + 1; i <= (level + k); i++){
        ans = min(ans, abs(a[level] - a[i]) + rec(i));
    }
    
    // Save and return
    return dp[level] = ans;
}

void solve(){
    cin >> n >> k;
    a.resize(n + 1);
    dp.assign(n + 1, -1); // Initialize dp with -1
    
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    cout << rec(1) << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
