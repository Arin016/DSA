#include<bits/stdc++.h>
using namespace std;
#define int long long

int mod = 1e9+7;

//look at the implementation
//s0
//s0p+s1
//s0p^2+s1p+s2
//.......

struct hasher {
    string s;
    int n, mod, p;
    vector<int> fhash;
    vector<int> pk;

    void init(const string& _s, int _p, int _mod) {
        s = _s;
        n = s.length();
        mod = _mod;
        p = _p;
        fhash.assign(n, 0);
        pk.assign(n, 0);
        fhash[0] = (s[0] - 'a' + 1);
        pk[0] = 1;
        for (int i = 1; i < n; i++) {
            fhash[i] = (fhash[i - 1] * p % mod + (s[i] - 'a' + 1)) % mod;
            pk[i] = (pk[i - 1] * p) % mod;
        }
    }

    int gethash(int l, int r) {
        int hash_val = fhash[r];
        if (l > 0) {
            hash_val = (hash_val - fhash[l - 1] * pk[r - l + 1] % mod + mod) % mod;
        }
        return hash_val;
    }
};

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.length(), m = b.length();

    hasher hasha, hashb;
    hasha.init(a, 31, mod);
    hashb.init(b, 31, mod);

    auto check = [&](int mid) -> bool {
        unordered_set<int> hashes;
        for (int i = 0; i + mid - 1 < n; i++) {
            hashes.insert(hasha.gethash(i, i + mid - 1));
        }
        for (int i = 0; i + mid - 1 < m; i++) {
            if (hashes.count(hashb.gethash(i, i + mid - 1))) return true;
        }
        return false;
    };

    int lo = 0, hi = min(n, m), ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
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
}
