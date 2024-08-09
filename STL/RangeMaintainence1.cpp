#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    //count the number of segments for each query in this manner;
    //lets say y is the point for which you want to know number of segments who cover y
    //total segments - (number of segments that dont cover y)
    //no of segments that dont cover y would be the ones whose ending point is before y and starting point is after y
    int n, q;
    cin>>n>>q;
    int l[n], r[n];
    for(int i=0;i<n;i++)cin>>l[i]>>r[i];
    sort(l, l+n);
    sort(r, r+n);
    while(q--){
        int y;
        cin>>y;
        int beforey = lower_bound(r, r+n, y)-r;
        int aftery = (l+n)-upper_bound(l, l+n, y);
        cout<<aftery+beforey<<endl;
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
