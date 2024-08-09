#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, t;
int a[1001001];

bool check(int mid){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=(mid/a[i]);
        if(sum>=t)return 1;
    }
    return 0;
}

void solve(){
    cin>>n>>t;
    int maxi = -1e9;
    for(int i=0;i<n;i++)cin>>a[i], maxi = max(maxi, a[i]);
    int lo = 0, hi = t*maxi, ans = t*maxi;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(check(mid)){
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
