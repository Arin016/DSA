#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


bool checkforlowerBound(int mid, vector<int> a, int x){
    return a[mid]>=x;
}

bool checkforupperBound(int mid, vector<int> a,int x){
    return a[mid]>x;
}

bool checkforrotatedSorted(int mid, vector<int> a){
    return a[mid]<a[0];
}

void solve(){
    int n, x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int lo = 0, hi = n-1, ans = n;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(checkforlowerBound(mid, a, x)){
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

