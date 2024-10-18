#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m, k;
vector<vector<int>> a;
vector<vector<vector<int>>> dp;

int rec(int i, int j, int kk){
    //pruning
    if(i<0||i>=n||j<0||j>=m)return 0;
    if(kk<0)return 0;
    //base case
    if(i==n-1 and j==m-1){
        return 1;
    }
    //cache check
    if(dp[i][j][kk]!=-1)return dp[i][j][kk];
    //compute
    int ans = 0;
    if(a[i+1][j]==1){
        (ans+=rec(i+1, j, kk-1))%=mod;
    }
    if(a[i][j+1]==1){
        (ans+=rec(i, j+1, kk-1))%=mod;
    }
    if(a[i+1][j]==0){
        (ans+=rec(i+1, j, kk))%=mod;
    }
    if(a[i][j+1]==0){
        (ans+=rec(i, j+1, kk))%=mod;
    }
    //save and return
    return dp[i][j][kk] = ans%=mod;
}
void solve(){
    cin>>n>>m>>k;
    a.assign(n+1, vector<int>(m+1, 0));
    dp.assign(n+1, vector<vector<int>>(m+1, vector<int>(k+1, -1)));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    if(a[0][0]==1)cout<<rec(0, 0, k-1)%mod<<endl;
    else cout<<rec(0, 0, k)%mod<<endl;
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
