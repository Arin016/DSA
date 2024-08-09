#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m, k;

bool check(int mid, vector<int>& a, vector<int>& b){
    int cnt = 0;
    for(auto x:a){
        auto it = upper_bound(b.begin(), b.end(), mid-x)-b.begin();
        cnt+=it;
        if(cnt>=k)return 1; //waw
    }
    return 0;
}

void solve(){
    cin>>n>>m>>k;
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    sort(a.begin(), a.end()), sort(b.begin(), b.end());
    if(n>m){
        swap(a, b);
    }
    int lo = a[0]+b[0], hi = a[n-1]+b[n-1], ans = hi;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(check(mid, a, b)){ //(no of ele <=x)>=k
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
    cin>>t;
    while(t--){
        solve();
    }
}
