#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e6+7;

signed main() {
    while (true) {
        int n, d;
        cin >> n >> d;
        if (n == 0 && d == 0) break;

        map<int, int> f;
        for (int i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                f[i]++;
                n /= i;
            }
        }
        if (n > 1) f[n]++;
        f[2] += d;
        f[5] += d;

        for (auto& x : f) x.second *= 2;

        int ans = 2;
        for (auto x : f) {
            ans = (ans * (x.second + 1)) % mod;
        }

        cout << ans - 1 << endl;
    }

    return 0;
}
