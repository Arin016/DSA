#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
string s;
vector<vector<int>> dp;

int rec(int l, int r){
    //pruning
    //base case
    if(l>=r)return 0;
    //cache check
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    //compute
    int ans = 1e18;
    if(s[l]==s[r]){
        ans = min(ans, rec(l+1, r-1));
    }
    else{
        ans = min(ans, 1+rec(l+1, r)); //insert at l
        ans = min(ans, 1+rec(l, r-1)); //insert at r
    }
    //save and return
    return dp[l][r] = ans;
}
void solve(){
    cin>>s;
    n = s.length();
    dp.assign(n+1, vector<int>(n+1, -1));
    cout<<rec(0, n-1)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
