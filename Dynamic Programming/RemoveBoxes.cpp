#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
vector<int> a;
vector<vector<vector<int>>> dp; 

int rec(int l, int r, int k){
    //maximum score you can get in l...r with k matches 
    //on right side of r who are same as r
    //pruning
    if(l>r)return 0;
    //base case
    while(l<r and a[r]==a[r-1]){
        r--;
        k++;
    }
    //cache check
    if(dp[l][r][k]!=-1)return dp[l][r][k];
    //compute
    int ans = -1e9;
    ans = max(ans, (k+1)*(k+1)+rec(l, r-1, 0));
    for(int i=l;i<=r-1;i++){
        if(a[i]==a[r]){
            ans = max(ans, rec(i+1, r-1, 0)+rec(l, i, k+1));
        }
    }
    //save and return
    return dp[l][r][k] = ans;

}

void solve(){
    cin>>n;
    a.resize(n+1);
    for(int i=0;i<n;i++)cin>>a[i];
    dp.assign(n+1, vector<vector<int>>(n+1, vector<int>(n+1, -1)));
    cout<< rec(0, n-1, 0) << endl;
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
