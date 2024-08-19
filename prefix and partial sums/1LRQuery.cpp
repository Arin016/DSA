#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i) (a[i] = (a[i] % mod + a[i - 1] % mod) + mod) %= mod;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int result = (l - 1 >= 0) ? ((a[r] - a[l - 1] + mod) % mod) : a[r] % mod;
        cout << result << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
