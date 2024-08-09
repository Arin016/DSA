#include <bits/stdc++.h>
using namespace std;
#define int long long

map<int, int> f;
int mod = 1000007;
int sp[1000100];

void spcalc() {
    for (int i = 2; i < 1000100; i++) {
        sp[i] = i;
    }
    for (int i = 2; i * i < 1000100; i++) {
        if (sp[i] == i) {
            for (int j = 2 * i; j < 1000100; j += i) {
                if (sp[j] == j) sp[j] = i;
            }
        }
    }
}

void primefact(int n) {
    for (int i = 1; i <= n; i++) {
        int val = i;
        while (val > 1) {
            f[sp[val]]++;
            val /= sp[val];
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    spcalc();
    primefact(n);
    for (auto &x : f) {
        x.second *= 2;
    }

    int ans = 1;
    for (auto x : f) {
        ans = (ans % mod * (1 + x.second) % mod) % mod;
    }

    cout << ans << endl;
}