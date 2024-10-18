#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int n;
vector<pair<int,pair<int,int>>> arr;
vector<int> dp;

int rec(int level){
    if(level>=n){
        return 0;
    }

    if(dp[level]!=-1){
        return dp[level];
    }

    int ans = 0;
    ans = max(ans,rec(level+1));
    int next = upper_bound(arr.begin(),arr.end(),make_pair(arr[level].S.F,make_pair(LLONG_MAX,LLONG_MAX)))-arr.begin();
    ans = max(ans,arr[level].S.S + rec(next));

    return dp[level] = ans;
}

void solve(){
    cin>>n;
    arr.clear();
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr.push_back({a,{b,c}});
    }

    sort(arr.begin(),arr.end());

    dp.assign(n+1,-1);
    cout<<rec(0)<<endl;

    // for(int level=n;level>=0;level--){
    //         if(level>=n){
    //             dp[level] = 0;
    //             continue;
    //         }

    //         int ans = 0;
    //         ans = max(ans,dp[level+1]);
    //         int next = upper_bound(arr.begin(),arr.end(),make_pair(arr[level].S.F,make_pair(LLONG_MAX,LLONG_MAX)))-arr.begin();
    //         ans = max(ans,arr[level].S.S + dp[next]);
    //         dp[level] = ans;
    // }
    // cout<<dp[0]<<endl;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}