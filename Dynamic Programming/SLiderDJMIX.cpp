#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, S;
vector<int> a;

int rec(int level, int s){
    //pruning
    if(s<0)return 0;
    //base case
    if(level==n){
        return s==0;
    }
    //cache check
    //compute
    int ans = 0;
    for(int i=0;i<=a[level];i++){
        ans+=rec(level+1, s-i);
    }
    //save and return
    return ans;
}

void solve(){
    cin>>n>>S;
    a.resize(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<rec(0, S)<<endl;
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
