#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
vector<vector<int>> a;
vector<vector<vector<int>>> dp;
int rec(int i, int j, int x, int y){
    //pruning
    if(i<0||i>=n||j<0||j>=m)return -1e18;
    if(x<0||x>=n||y<0||y>=m)return -1e18;
    //base case
    if(i==x and j==y and i==n-1 and j==m-1){
        return a[i][j];
    }
    //cache check
    if(dp[i][j][x]!=-1)return dp[i][j][x];
    //compute
    int ans = -1e18;
    int val = a[i][j]+a[x][y];
    if(i==x and j==y)val-=a[i][j];
    //RR
    ans = max(ans, val+rec(i, j+1, x, y+1));
    //RD
    ans = max(ans, val+rec(i, j+1, x+1, y));
    //DD
    ans = max(ans, val+rec(i+1, j, x+1, y));
    //DR
    ans = max(ans, val+rec(i+1, j, x, y+1));
    //save and return
    return dp[i][j][x] = ans;
}

void solve(){
    cin>>n>>m;
    a.assign(n+1, vector<int>(m+1, 0));
    dp.assign(n+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    cout<<rec(0, 0, 0, 0)<<endl;
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
