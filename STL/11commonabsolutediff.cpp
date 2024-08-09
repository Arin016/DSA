#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

//k = 2
//2 3 4 4 4 4

void solve1(){
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a, a+n);
    map<int, int> mp;
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=mp[a[i]]; //counting assuming it as aj
        mp[k+a[i]]++;   //updating for future assuming it as ai
    }  
    cout<<ans<<endl;
}


void solve(){
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a, a+n);
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=upper_bound(a+i, a+n, k+a[i])-lower_bound(a+i, a+n, k+a[i]);
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
