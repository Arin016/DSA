#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, S;
vector<int> a;

void solve(){
    cin>>n>>S;
    a.resize(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int dp[2][S+100];
    //deciding order of loops
    for(int level=n;level>=0;level--){
        for(int s=0;s<=S;s++){
            //pruning
            //base case
            if(level==n){
                dp[level&1][s] = (s==0);
                continue;
            }
            //cache check
            //compute
            //r = s, l = s-a[level] !!!
            int ans = dp[(level+1)&1][s];
            if(s-a[level]-1>=0){
                ans-=dp[(level+1)&1][s-a[level]-1];
            }
            // for(int i=0;i<=a[level];i++){
            //     if(s-i>=0)(ans+=dp[level+1][s-i])%=mod;
            // }
            //save and return
            dp[level&1][s] = ans;
        }
        //take prefix sum here for optimisation
        for(int s=1;s<=S;s++){
            dp[level&1][s]+=dp[level&1][s-1];
        }
    }
    //wherever you are accessing the dp array use &1!
    cout<<dp[0&1][S] - ((S-1>=0)?dp[0&1][S-1]:0)<<endl;
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
