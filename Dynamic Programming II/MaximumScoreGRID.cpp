#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m, k;
vector<vector<int>> a;
vector<vector<vector<int>>> dp;
int rec(int i, int j, int modk){
    //pruning
    if(i<0||i>=n||j<0||j>=m)return -1e18;
    //base case
    if(i==0){
        if((a[i][j]%k+modk%k)%k==0)return a[i][j];
        else return -1e18;
    }
    //cache check
    if(dp[i][j][modk]!=-1)return dp[i][j][modk];
    //compute
    int ans = -1e18;
    //go to (i-1, j-1)
    ans = max(ans, a[i][j]+rec(i-1, j-1, (modk%k+a[i][j]%k)%k));
    //go to (i-1, j+1)
    ans = max(ans, a[i][j]+rec(i-1, j+1, (modk%k+a[i][j]%k)%k));
    //save and return
    return dp[i][j][modk] = ans;
}
void solve(){
    cin>>n>>m>>k;
    a.assign(n+1, vector<int>(m+1));
    dp.assign(n+1, vector<vector<int>>(m+1, vector<int>(k+1, -1)));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            a[i][j] = s[j]-'0';
        }
    }
    int maxi = -1e18;
    for(int j=0;j<m;j++){
        maxi = max(maxi, rec(n-1, j, 0));
    }
    if(maxi<0)cout<<-1<<endl;
    else cout<<maxi<<endl;
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
