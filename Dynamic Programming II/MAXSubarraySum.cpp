#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
vector<int> a;

void solve(){
    cin>>n;
    a.resize(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int dp[n+1];
    //dp[i] = max subarray sum ending at i
    for(int i=0;i<=n;i++){
        if(i==0)dp[i] = a[i];
        else dp[i] = max(a[i], dp[i-1]+a[i]);
    }
    int ans = -1e18;
    for(int i=0;i<n;i++){
        ans = max(ans, dp[i]);
    }

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
