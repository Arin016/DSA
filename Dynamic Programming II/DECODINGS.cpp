#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

string s;
int n;
vector<int> dp;
int rec(int level){ //no of ways you could deocode level....n-1
    //pruning
    if(level>n)return 0;
    //base case
    if(level==n)return 1;
    //cache check
    if(dp[level]!=-1)return dp[level];
    //compute
    int ans = 0;
    int temp1 = stoll(s.substr(level, 1));
    int temp2 = stoll(s.substr(level, 2));
    if(temp1>=1 and temp1<=26){
        ans+=rec(level+1);
    }
    if(temp2>=10 and temp2<=26){
        ans+=rec(level+2);
    }
    //save and retun
    return dp[level] = ans;
}

void solve(){
    while(1){
        cin>>s;
        if(s=="0")break;
        n = s.length();
        dp.assign(n+1, -1);
        cout<<rec(0)<<endl;
    }
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
