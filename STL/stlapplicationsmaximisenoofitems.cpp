#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    int n, q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a, a+n); //uses intro sort
    int ans = 0;
    //basic version
    // for(int i=0;i<n;i++){
    //     if(a[i]<=b){
    //         b-=a[i];
    //         ans++;
    //     }
    //     else break;
    // }
    //query version
    for(int i=1;i<n;i++)a[i]+=a[i-1];
    while(q--){
        int b;
        cin>>b;
        auto it = upper_bound(a, a+n, b)-a; //number of elements <=b in a
        cout<<it<<endl;
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
