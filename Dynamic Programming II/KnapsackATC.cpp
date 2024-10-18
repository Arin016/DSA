#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define F first
#define S second 
#define int long long
const int mod = 1e9+7;
const int INF = 1e9;
using state = pair<int, int>;

int n, w;
int a[101][2];
int dp[101][100100];
int rec(int i, int x){
    //pruning
    if(x<0)return -1e18;
    //base case
    if(i==n)return 0;
    //cache check
    if(dp[i][x]!=-1)return dp[i][x];
    //compute
    int ans = rec(i+1, x);
    ans = max(ans, a[i][1]+rec(i+1, x-a[i][0]));
    //save and return
    return dp[i][x] = ans;
}

void solve(){
    cin>>n>>w;
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1];
    }
    cout<<rec(0, w)<<endl;
}

signed main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    int _t=1;
    //cin>>_t;
    while(_t--){
        solve();
    }
}