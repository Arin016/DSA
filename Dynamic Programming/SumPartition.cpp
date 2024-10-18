#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;
const int INF = 1e9;
int n, k;


/*
Find the number of unordered ways, 
N can be partitioned into K
positive integers (i.e >0 ), i.e sum of all K numbers must be N
*/
int dp[5001][5001];

int rec(int i, int x){
    //pruning  
    if(i<0)return 0;
    if(x==1)return 1;
    //base case
    //cache check
    if(dp[i][x]!=-1)return dp[i][x];
    //compute
    int ans = (rec(i-x, x)%mod + rec(i, x-1)%mod)%mod;
    //save and return
    return dp[i][x] = ans;
}

void solve(){
    cin>>n>>k;
    cout<<rec(n-k, k)%mod<<endl;
}

signed main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    int _t=1;
    cin>>_t;
    while(_t--){
        solve();
    }
}