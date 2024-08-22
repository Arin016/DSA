#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;

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
        if (l - 1 >= 0) {
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
        // Initialize with different primes
        a.init(s, 29, 999999931);
        b.init(s, 37, 999999929);
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

    int lexiorder(int i, int j, int len) {
        //compare lexi order of s1 = s[i....i+len-1] and s2 = s[j....j+len-1]
        //binary searching to find the common matched length in both these s1 and s2
        int lo = 1, hi = len, ans = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;  // A possible length
            if (getfhash(i, i + mid - 1) == getfhash(j, j + mid - 1)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if (ans == len) return 0;  // Both are the same s1 and s2
        if (s[i + ans] < s[j + ans]) return -1;  // s1 is smaller than s2
        else return 1;  // s1 is greater than s2
    }
};

int n;
doublehash ha;

bool cmp(int i, int j) {
    int len = n - max(i, j);
    int compval = ha.lexiorder(i, j, len);
    if (compval == 0) return i > j;  // So that i is put before j only if i is a greater index
    return compval == -1;
}

vector<int> getsuffixarray(string s) {
    n = s.length();  // Initialize n here
    ha.init(s);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = i;
    }
    sort(ans.begin(), ans.end(), cmp);
    return ans;
}

void solve() {
    string s;
    cin >> s;
    vector<int> suffix_array = getsuffixarray(s);
    for (int x : suffix_array) {
        cout << x << " ";
    }
    cout << endl;
    //remember the cyclic shift and then print lexi order wala ques the only construction 
    //you got to do is use s = s+s but this should be done making sure the ans array only 
    //has 0....n and not till 0....2n and get the suffix array out!
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
