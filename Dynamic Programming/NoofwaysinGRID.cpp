#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
vector<string> a;

int rec(int i, int j){ //no of ways to reach n-1 and m-1 from i, j
    //pruning
    if(i<0||i>=n||j<0||j>=n)return 0;
    if(a[i][j]=='#')return 0;
    //base case
    if(i==n-1 and j==m-1)return 1;
    //cache check
    //compute
    int ans = 0;
    ans+=rec(i, j+1);
    ans+=rec(i+1, j);
    //save and return
    return ans;
}

void solve(){
    cin>>n>>m;
    a.resize(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
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
