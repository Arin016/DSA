#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
vector<int> points;
vector<vector<int>> dp;

int rec(int l, int r){
    //pruning
    //base case
    if(l+1==r)return 0;
    //cache check
    if(dp[l][r]!=-1)return dp[l][r];
    //compute
    int ans = 1e18;
    for(int x=l+1;x<=r-1;x++){
        int cost = points[l]*points[x]*points[r];
        if(x==l+1){
            ans = min(ans, cost+rec(x, r));
        }
        else if(x==r-1){
            ans = min(ans, cost+rec(l, x));
        }
        else{
            ans = min(ans, cost+rec(l, x)+rec(x, r));
        }
    }
    //save and return
    return dp[l][r] = ans;
}
void solve(){
    cin>>n;
    dp.assign(n+1, vector<int>(n+1, -1));
    points.assign(n+1, 0);
    for(int i=0;i<n;i++){
        cin>>points[i];
    }
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
