#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
vector<int> a;
vector<pair<int, int>> dp;  // dp[level] holds the max product (first) and min product (second) starting from `level`
vector<int> done;  // done[level] is a flag to check if dp[level] has been computed

// rec function computes the max and min product of a contiguous subsequence starting at index `level`
pair<int, int> rec(int level){  
    // pruning
    // base case: if we've processed all elements, the product of an empty sequence is neutral {1, 1}
    if(level == n){
        return {1, 1};
    }
    
    // cache check
    if(done[level] == 1) return dp[level];
    
    // compute
    pair<int, int> ans = {-1e18, 1e18}; 
    
    pair<int, int> next = rec(level + 1);  // Get results from the next level

    // max product can be the element itself, or the element times the max/min product of the rest of the sequence
    ans.first = max({ans.first, a[level], a[level] * next.first, a[level] * next.second});
    
    // min product similarly can be the element itself, or the element times the max/min product of the rest
    ans.second = min({ans.second, a[level], a[level] * next.first, a[level] * next.second});
    
    // save and return
    done[level] = 1;
    return dp[level] = ans;
}

void solve(){
    cin >> n;
    
    a.resize(n);
    dp.resize(n + 1);
    done.assign(n + 1, 0); 
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    // Initialize the max product as a very small value
    int maxi = -1e18;
    
    // Try to compute the max product starting from each index because thats what the meaning of the state
    for(int i = 0; i < n; i++){
        maxi = max(maxi, rec(i).first);
    }
    
    
    cout << maxi << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;  
    
    while(t--){
        solve();
    }
}
