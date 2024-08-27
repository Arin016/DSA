
#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int l = 0, r = n-1;
    int ans = -1e9;
    while(l<r){
        ans = max(ans, min(a[l], a[r])*(r-l));
        if(a[l]<a[r]){
            l++;
        }
        else{
            r--;
        }
    }
    cout<<ans<<endl;
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