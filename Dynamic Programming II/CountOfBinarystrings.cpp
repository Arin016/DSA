#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7; 

int n;
string t = "0100";

int dp[1000100][5];
int rec(int level,int match){
    if(match==4)return 0;
    if(level<0)return 1;
    if(dp[level][match]!=-1)return dp[level][match];
    int ans=0;
    if(match==0){
        ans=rec(level-1,0)+rec(level-1,1);
    }
    else if(match==1){
        ans=rec(level-1,1)+rec(level-1,2);
    }
     else if(match==2){
        ans=rec(level-1,3)+rec(level-1,0);
    }
     else if(match==3){
        ans=rec(level-1,4)+rec(level-1,2);
    }
    return dp[level][match]=ans%mod;
}

void solve(){
    cin>>n;
    cout<<rec(n-1,0)<<endl;
}

signed main() {
 ios_base::sync_with_stdio(false);
 	cin.tie(0); cout.tie(0);
	memset(dp, -1, sizeof(dp));
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }

}