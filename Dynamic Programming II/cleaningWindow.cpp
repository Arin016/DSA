#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
vector<vector<int>> a;
vector<vector<int>> dp;

int rec(int i, int j){
    //pruning
    if(i<0||j<0||i>=n||j>=m)return 0;
    //base case
    if(i==0){ //any first row window would have the last instant it was dirty as its own cleaning time!
        return a[i][j];
    }
    //cache check
    if(dp[i][j]!=-1)return dp[i][j];
    //compute
    int ans = a[i][j];
    ans = max(ans, rec(i-1, j));
    ans = max(ans, rec(i-1, j-1));
    ans = max(ans, rec(i-1, j+1));
    //save and return
    return dp[i][j] = ans;
}

void solve(){
    cin>>n>>m;
    a.assign(n+1, vector<int>(m+1, 0));
    dp.assign(n+1, vector<int>(m+1, -1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]>=rec(i, j)){ //rec(i, j) --> last time instant when this window was dirty
                cout<<1;
            }
            else cout<<0;
        }
        cout<<endl;
    }
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
