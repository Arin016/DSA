#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, X;
vector<int> coins;

int rec(int level, int x){
    //pruning
    if(x<0)return 0;
    //base case
    if(level==n){
        return x==0;
    }
    //cache check
    //compute
    int ans = rec(level+1, x);
    ans |= rec(level, x-coins[level]);
    //save and return
    return ans;
}

void solve(){
    cin>>n>>X;
    coins.resize(n+1);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    cout<<rec(0, X)<<endl;
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
