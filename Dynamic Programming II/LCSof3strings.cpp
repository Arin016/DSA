#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m, o;
string a, b, c;
vector<vector<vector<int>>> dp;
int rec(int i, int j, int k){ //LCS in i, j, k ...... n-1, m-1, o-1
    //pruning
    if(i>n || j>m || k>o)return 0;
    //base case
    if(i==n and j==m and k==o)return 0; 
    //cache check
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    //compute
    int ans = 0;
    if(a[i]==b[j] and b[j]==c[k] and c[k]==a[i]){
        ans = max(ans, 1+rec(i+1, j+1, k+1));
    }
    else{
        ans = max(ans, rec(i+1, j, k));
        ans = max(ans, rec(i, j+1, k));
        ans = max(ans, rec(i, j, k+1));
    }
    //save and return
    return dp[i][j][k] = ans;
}

void solve(){
    cin>>a>>b>>c;
    n = a.length(), m = b.length(), o = c.length();
    dp.assign(n+1, vector<vector<int>>(m+1, vector<int>(o+1, -1)));
    cout<<rec(0, 0, 0)<<endl;
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
