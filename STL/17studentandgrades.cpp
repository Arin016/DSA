#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    int n, m;
    cin>>n>>m;
    map<int, int> mp;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mp[x]++;
    }
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        if(mp.count(x))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        mp[x]++;
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
