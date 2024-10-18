#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


int n, k;
vector<int> a;
vector<vector<int>> dp;
int rec(int i, int kk){
    //pruning
    if(kk<0)return 1e18;
    //base case
    if(i==n){
        if(kk==0)return 0;
        else return 1e18;
    }
    //cache check
    if(dp[i][kk]!=-1)return dp[i][kk];
    //compute
    int ans = 1e18;
    int maxi = a[i];
    for(int j=i;j<n;j++){
        maxi = max(maxi, a[j]);
        ans = min(ans, maxi+rec(j+1, kk-1));
    }
    //save and return
    return dp[i][kk] = ans;
}

void printsol(int i, int kk){
    // pruning
    if(kk < 0) return;
    // base case
    if(i == n){
        if(kk == 0) return;
        else return;
    }
    
    // compute solution to match with rec()
    int ans = rec(i, kk);
    int maxi = a[i];
    for(int j=i;j<n;j++){
        maxi = max(maxi, a[j]);
        if(ans==maxi+rec(j+1, kk-1)){
            cout << maxi << " ";
            printsol(j + 1, kk - 1);
            return; // yeh return marana zaruri hai
        }
    }
}


void solve(){
    cin>>n>>k;
    a.resize(n+1);
    dp.assign(n+1, vector<int>(k+1, -1));
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<rec(0, k)<<endl;
    printsol(0, k);
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
