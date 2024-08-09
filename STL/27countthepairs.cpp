#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    int n, x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a, a+n);
    int ans = 0;
    for(int i=0;i<n;i++){
        //Method 1:
        // int val = upper_bound(a, a+n, x-a[i])-(a);
        // if(a[i]<=x-a[i])val--; //WAWW!!
        // ans+=val;
        //Method 2:
        int val = upper_bound(a+i+1, a+n, x-a[i])-(a+i+1);
        ans+=val;
    }
    cout<<ans+ans<<endl; //i, j and j, i
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
