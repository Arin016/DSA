#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, k;

bool check(int mid){
    int cnt = 0;
    for(int i=1;i<=n;i++){
        cnt+=min(mid/i, n); //i*j<=mid //derived from the way the problem statement is constructed
    }
    return cnt>=k;
}

void solve(){
    cin>>n;
    k = (n*n+1)/2;
    int lo = 1, hi = n*n, ans = -1;
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
