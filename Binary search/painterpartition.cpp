#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


int n, k;
int a[1001001];

bool check(int mid){
    int tleft = 0;
    int pspawn = 0;
    for(int i=0;i<n;i++){
        if(tleft>=a[i])tleft-=a[i];
        else{
            pspawn++;
            tleft=mid;
            if(a[i]>tleft)return 0;
            tleft-=a[i];
        }
    }
    return pspawn<=k;
}

void solve(){
    cin>>n>>k;
    int sum = 0;
    for(int i=0;i<n;i++)cin>>a[i], sum+=a[i];
    int lo = 0, hi = sum, ans = sum;
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
    //cin>>t;
    while(t--){
        solve();
    }
}
