#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
string s;
vector<int> a;
string t = "hard";
vector<vector<int>> dp;

int rec(int level, int match){
    //pruning
    if(match==4)return 1e18;
    //base case
    if(level==n)return 0;
    //cache check
    if(dp[level][match]!=-1)return dp[level][match];
    //compute
    int ans = 1e18;
    if(match==0){
        if(s[level]=='h'){
            ans = min(ans, rec(level+1, 1));
            ans = min(ans, a[level]+rec(level+1, 0));
        }
        else ans = min(ans, rec(level+1, match));
    }
    else if(match==1){
        if(s[level]=='a'){
            ans = min(ans, rec(level+1, 2));
            ans = min(ans, a[level]+rec(level+1, 1));
        }
        else ans = min(ans, rec(level+1, match));
    }
    else if(match==2){
        if(s[level]=='r'){
            ans = min(ans, rec(level+1, 3));
            ans = min(ans, a[level]+rec(level+1, 2));
        }
        else ans = min(ans, rec(level+1, match));
    }
    else if(match==3){
        if(s[level]=='d'){
            ans = min(ans, a[level]+rec(level+1, 4));
            ans = min(ans, a[level]+rec(level+1, 3));
        }
        else ans = min(ans, rec(level+1, match));
    }
    //save and return
    return dp[level][match] = ans;
}
void solve(){
    cin>>n>>s;
    dp.assign(n+1, vector<int>(5, -1));
    a.resize(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<rec(0, 0)<<endl;
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
