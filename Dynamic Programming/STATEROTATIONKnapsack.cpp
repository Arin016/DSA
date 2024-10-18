#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, W;
vector<int> w, v;
vector<vector<int>> dp;

int rec(int level, int V){ //min "weight" cost to accumulate V amount of value in level...n-1 
    //pruning
    if(V<0)return 0;
    //base case
    if(level==n){
        if(V==0)return 0;
        else return 1e18;
    }
    //cache check
    if(dp[level][V]!=-1)return dp[level][V];
    //compute
    int ans = 1e18;
    //pick this weight and reduce the value
    ans = min(ans, w[level]+rec(level+1, V-v[level]));
    //skip this weight
    ans = min(ans, rec(level+1, V));
    //save and return
    return dp[level][V] = ans;
}

void solve(){
    cin>>n>>W;
    w.resize(n+1);
    v.resize(n+1);
    dp.assign(n+1, vector<int>(1e5+100, -1));
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    int maxi = -1e18;
    for(int val=0;val<=1e5;val++){
        if(rec(0, val)<=W){
            maxi = max(maxi, val);
        }
    }
    cout<<maxi<<endl;
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
