#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m, b;
vector<int> a;
vector<vector<vector<int>>> dp;
int rec(int level, int mm, int bb){
    //pruning
    if(bb>b)return 0;
    if(mm>m)return 0;
    //base case
    if(level==n){
        return mm==m;
    }
    //cache check
    if(dp[level][mm][bb]!=-1)return dp[level][mm][bb];
    //compute
    int ans = 0;
    //take
    ans = (ans%mod + rec(level, mm+1, bb+a[level])%mod)%mod;
    //dont take
    ans = (ans%mod + rec(level+1, mm, bb)%mod)%mod;
    //save and return
    return dp[level][mm][bb] = ans;
}
void solve(){
    cin>>n>>m>>b;
    a.resize(n+1);
    dp.assign(n+1, vector<vector<int>>(m+1, vector<int>(b+1, -1)));
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<rec(0, 0, 0)<<endl;
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
