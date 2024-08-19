#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int binpowi(int a, int b, int mod){
    a %= mod;
    int res = 1;
    while(b > 0){
        if(b & 1){ 
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res % mod;
}

int inverse(int a, int mod){
    return binpowi(a, mod-2, mod);
}

void solve(){
    int n, q, k;
    cin >> n >> q >> k;
    //the range could be represented as ΣLtoR(aj*k^(j-L))
    //split the expression and kill it seperately
    int arr[n+1] = {0};
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    int prefix[n+1] = {0};
    for(int i = 1; i <=  n; i++){
        prefix[i] = ((prefix[i-1]+mod)%mod+ (((arr[i] + mod)%mod)* binpowi(k, i, mod)%mod)%mod + mod) % mod;
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        int sum = (prefix[r] - prefix[l-1] + mod) % mod;
        sum = (sum * inverse(binpowi(k, l, mod), mod)) % mod;
        cout << sum << endl;
    }
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