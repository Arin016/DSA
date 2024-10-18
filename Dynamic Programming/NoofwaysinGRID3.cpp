#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m, k;
vector<vector<int>> a;
vector<vector<vector<int>>> dp; 

void solve(){
    cin>>n>>m>>k;
    a.assign(n+1, vector<int>(m+1, 0));
    dp.assign(n+1, vector<vector<int>>(m+1, vector<int>(k+1, -1)));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    //ordering of loops
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            for(int kk=k;kk>=0;kk--){
                //base case
                if(i==n-1 and j==m-1){
                    dp[i][j][kk] = 1;
                    continue;
                }
                //compute
                int ans = 0;
                if(i+1>=0 and i+1<n and a[i+1][j]==0){
                    ans = (ans%mod + dp[i+1][j][0])%mod%mod;
                }  
                if(j+1>=0 and j+1<m and kk+1<=k and a[i][j+1]==0){
                    ans = (ans%mod + dp[i][j+1][kk+1]%mod)%mod;
                }
                //save and return
                dp[i][j][kk] = ans;
            }
        }
    }
    cout<<dp[0][0][0]<<endl;
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
