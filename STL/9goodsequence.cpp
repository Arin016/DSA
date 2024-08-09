#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    int n;
    cin>>n;
    int a[n];
    map<int, int> f;
    for(int i=0;i<n;i++)cin>>a[i], f[a[i]]++;
    int cnt = 0;
    for(auto x:f){
        if(x.second>=x.first)cnt+=x.second-x.first;
        else cnt+=x.second;
    }
    cout<<cnt<<endl;

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
