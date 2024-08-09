#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;


//store all the distances in a set take the max out slice it into 2 parts reduce ks value by one put the new
//distances into the set repeat this till k gets over

int n,k;
vector<int> arr;

bool check(int mid){
    int temp = k;
    for(int i=1;i<n;i++){
        temp = temp - ((arr[i]-arr[i-1]+mid-1)/mid  - 1);   //formula: ceil((x2-x1)/mid)-1
        if(temp<0){
            return 0;
        }
    }
    return 1;
}

void solve(){
    cin>>n>>k;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());

    int lo = 1;
    int hi = 1e18;
    int ans = 0;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(check(mid)){
            ans = mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    cout<<ans<<endl;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}