#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
//nothing from within the rec should depend upon something that isnt a part of the rec function

int n, W;
vector<int> w, v;
vector<vector<int>> dp;
int rec(int level, int wleft){
    //pruning
    if(wleft<0)return -1e9; //maximisation problem!
    //base case
    if(level==n)return 0;
    //cache check
    if(dp[level][wleft]!=-1)return dp[level][wleft];
    //compute
    int ans = -1e9;
    //take it, we dont necessarily have to go to next level in 0-INF
    ans = max(ans, v[level]+rec(level, wleft-w[level]));
    //dont take it
    ans = max(ans, rec(level+1, wleft));
    //save and return
    return dp[level][wleft] = ans;
}

void solve(){
    cin>>n>>W;
    w.resize(n+1);
    v.resize(n+1);
    for(int i=0;i<n;i++)cin>>w[i];
    for(int i=0;i<n;i++)cin>>v[i];
    dp.assign(n+1, vector<int>(W+1, -1));
    cout<<rec(0, W)<<endl;
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
