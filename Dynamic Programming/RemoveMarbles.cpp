#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
vector<int> a;
vector<vector<vector<int>>> dp;
int rec(int l, int r, int kk){
    //pruning
    if(l>r)return 0;
    //base case
    while(r>l and a[r-1]==a[r]){
        r--;
        kk++;
    }
    //cache check
    if(dp[l][r][kk]!=-1)return dp[l][r][kk];
    //compute
    int ans = -1e18;
    ans = max(ans, (kk+1)*(kk+1)+rec(l, r-1, 0));
    for(int k=l;k<r;k++){
        if(a[k]==a[r]){
            ans = max(ans, rec(l, k, kk+1)+rec(k+1, r-1, 0));
        }
    }
    //save and return
    return dp[l][r][kk] = ans;
}

void solve(){
    cin>>n;
    a.resize(n+1);
    dp.assign(n+1, vector<vector<int>>(n+1, vector<int>(n+1, -1)));
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<rec(0, n-1, 0)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
