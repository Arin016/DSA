#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

string l, r;
int n;
string k;
int d;
int dp[10001][2][2][101];
int rec(int level, int tlo, int thi, int summod){
    //pruning
    //base case
    if(level==n){
        return summod==0;
    }
    //cache check
    if(dp[level][tlo][thi][summod]!=-1)return dp[level][tlo][thi][summod];
    //compute
    int ans = 0;
    int lo = 0, hi = 9;
    if(tlo==1){
        lo = l[level]-'0';
    }
    if(thi==1){
        hi = r[level]-'0';
    }
    for(int i=lo;i<=hi;i++){
        int newtlo = tlo, newthi = thi;
        if(i!=lo){
            newtlo = 0;
        }
        if(i!=hi){
            newthi = 0;
        }   
        ans = (ans%mod + rec(level+1, newtlo, newthi, (summod+i)%d)%mod)%mod;
    }
    //save and return
    return dp[level][tlo][thi][summod] = ans;
}

void solve(){
    cin>>k>>d;
    l = "1", r = k;
    int zeroes = r.length()-l.length();
    string extra = "";
    while(zeroes--){
        extra+='0';
    }
    l = extra+l;
    n = l.length();
    memset(dp, -1, sizeof(dp));
    cout<<rec(0, 1, 1, 0)<<endl;
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
