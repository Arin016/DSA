#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, X;
vector<int> coins;

int rec(int level, int x){
    //pruning
    if(x<0)return 0;
    //base case
    if(level==n){
        return x==0;
    }
    //cache check
    //compute
    int ans = rec(level+1, x);
    ans |= rec(level, x-coins[level]);
    //save and return
    return ans;
}

void solve(){
    cin>>n>>X;
    coins.resize(n+1);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    int dp[n+1][X+1];
    //deciding order of loops
    for(int level=n;level>=0;level--){
        for(int x=0;x<=X;x++){
            //pruning get rid of pruning in case of iterative instead keep the 
            //checks during transitioing
            //base case
            if(level==n){
                dp[level][x] = (x==0);
                continue;
            }
            //cache check
            //compute
            int ans = dp[level+1][x];
            if(x>=0)ans |= dp[level][x-coins[level]];
            //save and return
            dp[level][x] =  ans;
        }
    }
    cout<<dp[0][X]<<endl;
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
