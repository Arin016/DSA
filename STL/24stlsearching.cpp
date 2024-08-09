#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    int n, q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a, a+n);
    while(q--){
        int y, x;
        cin>>y>>x;
        if(y==1){
            auto it = lower_bound(a, a+n, x);
            if(it==a+n)cout<<-1<<" ";
            else cout<<*it<<" ";
        }
        else if(y==2){
            auto it = upper_bound(a, a+n, x);
            if(it==a+n)cout<<-1<<" ";
            else cout<<*it<<" ";
        }
        else if(y==3){
            auto it = upper_bound(a, a+n, x)-a;
            cout<<it<<" ";
        }
        else{
            auto it = lower_bound(a, a+n, x)-a;
            cout<<it<<" ";
        }
    }
    cout<<endl;
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
