#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int premaxi[n], suffmaxi[n];
    premaxi[0] = a[0];
    for(int i=1;i<n;i++){
        premaxi[i] = max(premaxi[i-1], a[i]);
    }
    suffmaxi[n-1] = a[n-1];
    for(int i=n-2;i>=0;i--){
        suffmaxi[i] = max(suffmaxi[i+1], a[i]);
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=max(min(suffmaxi[i], premaxi[i])-a[i], 0LL);
    }
    cout<<ans<<endl;
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
