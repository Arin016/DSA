#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    multiset<int> mt1, mt2;

    for (int i = 0; i < n; i++) {
        int x, u;
        cin >> x >> u;
        mt1.insert(x * u);
    }

    for (int i = 0; i < m; i++) {
        int y, v;
        cin >> y >> v;
        mt2.insert(y * v);
    }

    int ans = 0;
    for (auto x : mt1) {
        auto it = mt2.find(x);
        if (it != mt2.end()) {
            ans++;
            mt2.erase(it);
        }
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
