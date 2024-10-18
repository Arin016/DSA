#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

string a, b;
int n, m;
vector<vector<int>> dp;

int rec(int i, int j){ //minimum cost required to convert i.....n-1 into j....m-1
    //pruning
    if(i<n and j==m){
        return n-i; //if j is over then to convert i...n-1 youll have to delete all of i...n-1
    }
    if(j<m and i==n){
        return m-j;
    }
    //base case
    if(i==n and j==m)return 0;
    //cache check
    if(dp[i][j]!=-1)return dp[i][j];
    //compute  
    int ans = 1e18;
    if(a[i]==b[j]){
        ans = min(ans, rec(i+1, j+1));
    } 
    else{
        ans = min(ans, 1+rec(i, j+1)); //insert in i
        ans = min(ans, 1+rec(i+1, j)); //delete in i
        ans = min(ans, 1+rec(i+1, j+1)); //replace
    }
    //save and return
    return dp[i][j] = ans;
}

void solve(){
    cin>>a>>b;
    n = a.length(), m = b.length();
    dp.assign(n+1, vector<int>(m+1, -1));
    cout<<rec(0, 0)<<endl;
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
