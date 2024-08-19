#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n), p(n), w(n);
    //the range could be represented as ΣLtoR(aj*(j-L+1))
    //split the expression and kill it seperately
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[i] = a[i]%mod;
        w[i] = (a[i]%mod * (i)%mod + mod) % mod;
        if (i) p[i] = (p[i]%mod + p[i-1]%mod + mod) % mod;
        if (i) w[i] = (w[i]%mod + w[i-1]%mod + mod) % mod;
    }
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--; 
        
        int term1 = (l-1 >= 0) ? (w[r]%mod - w[l-1]%mod + mod) % mod : w[r]%mod;
        int term2 = (l-1 >= 0) ? (p[r]%mod - p[l-1]%mod + mod) % mod : p[r]%mod;
        int result = (term1%mod + (((1-l)%mod * term2%mod)+mod % mod) + mod) % mod;
        
        cout << result << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
