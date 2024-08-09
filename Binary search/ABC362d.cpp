#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;


void solve() {
    int n, q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a, a+n);
    while(q--){
        int b, k;
        cin>>b>>k;
        //binary search on ans for distance
        //Find the distance between points x and b where x is the kth smallest neighbour

        auto check = [&](int mid)->bool{
            //#of points in [b-mid, b+mid]>=k //(similar to # of ele<=x)>=k
            //implicit kinda 2d BS
            auto it1 = lower_bound(a, a+n, b-mid);
            auto it2 = upper_bound(a, a+n, b+mid);
            return it2-it1>=k;
        };
        int lo = 0, hi = 1e9, ans = 1e9;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(check(mid)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        cout<<ans<<endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    
    return 0;
}
