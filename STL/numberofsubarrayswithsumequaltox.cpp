#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    //in the presence of negative numbers you cant use two pointers
    //prefix sum + map
    //number of subarrays with sum = x
    int n, x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i)a[i]+=a[i-1];
    }
    map<int, int> mp;
    mp[0]++; //this is important
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=mp[a[i]-x];
        mp[a[i]]++;
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
