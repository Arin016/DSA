#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
#define endl "\n"

int n, k;
map<int, int> mp;
vector<int> a;
vector<vector<int>> dp;

void solve(){
    cin>>n>>k;
    mp.clear();
    a.clear();
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        mp[temp]++;
    }
    for(auto x:mp){
        a.push_back(x.second);
    }
    if(k>=(int)(a.size()))k = (int)(a.size());
    dp.assign((int)(a.size())+1, vector<int>(k+1, -1));
    //ordering of loops
    for(int level=a.size();level>=0;level--){
        for(int kk=k;kk>=0;kk--){
            //base case
            if(level==a.size()){
                dp[level][kk] = 1;
                continue;
            }
            //compute
            int ans = 0;
            //dont include the current prime
            ans = (ans%mod + dp[level+1][kk]%mod)%mod;
            //include the current prime
            if(kk+1<=k)ans = (ans%mod + (dp[level+1][kk+1]%mod*a[level]%mod)%mod)%mod;
            //save and return
            dp[level][kk] = ans;
        }
    }
    cout<<dp[0][0]%mod<<endl;
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
