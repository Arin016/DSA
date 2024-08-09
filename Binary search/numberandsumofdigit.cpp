#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, s;

int sod(int x){
    int val = 0;
    while(x){
        val+=x%10;
        x/=10;
    }
    return val;
}

bool check(int mid){
    return (mid-sod(mid))>=s;
}

void solve(){
    cin >> n >> s;
    int lo = 1, hi = n, ans = n+1;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(check(mid)){
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    if(ans>n)cout<<0<<endl;
    else cout<<n-ans+1<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}