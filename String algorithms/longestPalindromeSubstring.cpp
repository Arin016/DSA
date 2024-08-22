#include <bits/stdc++.h>
using namespace std;
#define int long long

struct hasher {
    string s;
    int n, mod, p;
    vector<int> fhash, rhash, pk;

    void init(const string& _s, int _p, int _mod) {
        s = _s;
        n = s.length();
        mod = _mod;
        p = _p;

        fhash.assign(n, 0);
        rhash.assign(n, 0);
        pk.assign(n, 0);

        fhash[0] = (s[0] - 'a' + 1);
        rhash[n - 1] = (s[n - 1] - 'a' + 1);
        pk[0] = 1;

        for (int i = 1; i < n; i++) {
            fhash[i] = (fhash[i - 1] * p % mod + (s[i] - 'a' + 1)) % mod;
            rhash[n - 1 - i] = (rhash[n - 1 - i + 1] * p % mod + (s[n - 1 - i] - 'a' + 1)) % mod;
            pk[i] = (pk[i - 1] * p) % mod;
        }

    }

    int getfhash(int l, int r) {
        int hash_val = fhash[r];
        if (l > 0) {
            hash_val = (hash_val - fhash[l - 1] * pk[r - l + 1] % mod + mod) % mod;
        }
        return hash_val;
    }

    int getrhash(int l, int r) {
        int hash_val = rhash[l];
        if (r + 1 < n) {
            hash_val = (hash_val - rhash[r + 1] * pk[r - l + 1] % mod + mod) % mod;
        }
        return hash_val;
    }
};

struct doublehash {
    string s;
    hasher a, b;

    void init(const string& _s) {
        s = _s;
        a.init(s, 37, 999999931);
        b.init(s, 29, 999999929);
    }

    pair<int, int> getfhash(int l, int r) {
        return {a.getfhash(l, r), b.getfhash(l, r)};
    }

    pair<int, int> getrhash(int l, int r) {
        return {a.getrhash(l, r), b.getrhash(l, r)};
    }

    bool is_palin(int l, int r) {
        return getfhash(l, r) == getrhash(l, r);
    }
};

int n;
doublehash ha;

pair<int, int> manacher(string s) {
    n = s.length();
    ha.init(s);

    int fans = 0;
    int ind = 0;

    // Odd length palindromes (center is a character)
    for (int i = 0; i < n; i++) {
        int lo = 1, hi = min(i - 0 + 1, (n - 1) - i + 1), ans = 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (ha.is_palin(i - mid + 1, i + mid - 1)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        int len = 2 * ans - 1;
        if (len > fans) {
            fans = len;
            ind = i - ans + 1;
        }
    }

    // Even length palindromes (center is between characters)
    for (int i = 0; n > 1 && i < n - 1; i++) {
        int lo = 0, hi = min(i - 0 + 1, (n - 1) - (i+1) + 1), ans = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (ha.is_palin(i - mid + 1, (i+1) + mid - 1)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        int len = 2 * ans;
        if (len > fans) {
            fans = len;
            ind = i - ans + 1;
        }
    }

    return {fans, ind};
}

void solve() {
    string s;
    cin >> s;
    pair<int, int> ans = manacher(s);
    cout << s.substr(ans.second, ans.first) << endl;
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
}
