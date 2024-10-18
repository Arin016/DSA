#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr[i] = __builtin_popcount(x);
    }

    for(int i = 1; i < n; i++){
        arr[i] += arr[i-1];
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        int curr = (i > 0 ? arr[i-1] : 0);
        int req = curr + k;
        auto it = upper_bound(arr.begin() + i, arr.end(), req);
        if(it != arr.end()){
            int r = it - arr.begin();
            ans += (n - r);
        }
    }

    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}