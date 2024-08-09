#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, k;
int a[1000100];

bool check(int mid){
    int cnt = 1;
    int prev = 0;
    for(int i=1;i<n;i++){
        if(a[i]-a[prev]>=mid){
            cnt++;
            prev = i;
        }
    }
    return cnt>=k;
}

void solve(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)cin>>a[i];
    sort(a, a+n);
    int lo = 0, hi = 1e18, ans = 0;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(check(mid)){
            ans = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }
    cout<<ans<<endl;
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