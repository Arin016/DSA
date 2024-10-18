#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
int ll, rr;
string l, r;
string getbin(int x){
    string ans = "";
    while(x){
        ans+=to_string((x%2));
        x/=2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int dp[65][2][2][2][2];
int rec(int level, int tlo1, int thi1, int tlo2, int thi2){
    //pruning
    //base case
    if(level==n){
        return 0;
    }
    //cache check
    if(dp[level][tlo1][thi1][tlo2][thi2]!=-1)return dp[level][tlo1][thi1][tlo2][thi2];
    //compute
    int ans = 0;
    int lo1 = 0, hi1 = 1;
    if(tlo1==1){
        lo1 = l[level]-'0';
    }
    if(thi1==1){
        hi1 = r[level]-'0';
    }
    int lo2 = 0, hi2 = 1;
    if(tlo2==1){
        lo2 = l[level]-'0';
    }
    if(thi2==1){
        hi2 = r[level]-'0';
    }
    for(int i=lo1;i<=hi1;i++){
        for(int j=lo2;j<=hi2;j++){
            int newtlo1 = tlo1, newthi1 = thi1;
            if(i!=lo1)newtlo1 = 0;
            if(i!=hi1)newthi1 = 0;
            int newtlo2 = tlo2, newthi2 = thi2;
            if(j!=lo2)newtlo2 = 0;
            if(j!=hi2)newthi2 = 0;
            ans = max(ans, (((i^j)<<(n-1-level)) + rec(level+1, newtlo1, newthi1, newtlo2, newthi2)));
        }
    }
    //save and return
    return dp[level][tlo1][thi1][tlo2][thi2] = ans;
}
void solve(){
    cin>>ll>>rr;
    l = getbin(ll);
    r = getbin(rr);
    int zeroes = r.length()-l.length();
    string extra = "";
    while(zeroes--){
        extra+='0';
    }
    l = extra + l;
    n = l.length();
    memset(dp, -1, sizeof(dp));
    cout<<rec(0, 1, 1, 1, 1)<<endl;
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
