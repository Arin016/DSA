#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
vector<string> a;
vector<vector<vector<int>>> dp;
int rec(int i, int j, int x, int y){
    // pruning
    if(i<0 || i>=n || j<0 || j>=m) return 0;
    if(x<0 || x>=n || y<0 || y>=m) return 0; 
    if(i>x || j>y)return 0;
    // base case
    // odd length palindrome
    if(i == x && j == y) return 1; 
    // even length palindrome
    if(i+1<n and i+1 == x && j == y) return (a[i][j] == a[x][y]);
    if(j+1<m and i == x && j+1 == y) return (a[i][j] == a[x][y]);

    // cache check 
    if(dp[i][j][x]!=-1)return dp[i][j][x];
    // compute
    int ans = 0;
    if(i+1<n && x-1>=0 && a[i+1][j] == a[x-1][y]){
        ans = (ans%mod + rec(i+1, j, x-1, y)%mod)%mod;
    }
    if(i+1<n && y-1>=0 && a[i+1][j] == a[x][y-1]){
        ans = (ans%mod + rec(i+1, j, x, y-1)%mod)%mod;
    }
    if(j+1<m && x-1>=0 && a[i][j+1] == a[x-1][y]){
        ans = (ans%mod + rec(i, j+1, x-1, y)%mod)%mod;
    }
    if(j+1<m && y-1>=0 && a[i][j+1] == a[x][y-1]){
        ans = (ans%mod + rec(i, j+1, x, y-1)%mod)%mod;
    }

    //save and return
    return dp[i][j][x] = ans%mod;
}

void solve(){
    cin >> n >> m;
    a.resize(n);
    dp.assign(n+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(a[0][0]!=a[n-1][m-1]){
        cout<<0<<endl;
    }
    else cout << rec(0, 0, n-1, m-1) << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}