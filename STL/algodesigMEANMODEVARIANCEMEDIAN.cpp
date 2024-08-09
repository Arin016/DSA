#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int binpow(int base, int exp, int mod) {
    int res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * 1LL * base) % mod;
        }
        base = (base * 1LL * base) % mod;
        exp /= 2;
    }
    return res;
}

int bin_div(int a, int b) {
    return (a * 1LL * binpow(b, MOD - 2, MOD)) % MOD;
}

struct DataDashboard {
    // Mean
    int sum = 0;
    int count = 0;

    // Variance
    int sumsq = 0;

    // Mode
    map<int, int> freq;
    multiset<pair<int, int>> freq_order;

    // Median
    multiset<int> low, high;

    void balance() {
        while (high.size() > low.size()) {
            int x = *high.begin();
            high.erase(high.find(x));
            low.insert(x);
        }
        while (low.size() > high.size() + 1) {
            int x = *low.rbegin();
            low.erase(low.find(x));
            high.insert(x);
        }
    }

    void insert(int x) {
        count++;
        sum = (sum + x) % MOD;
        sumsq = (sumsq + (x * 1LL * x) % MOD) % MOD;

        // Mode
        if (freq_order.find({-freq[x], x}) != freq_order.end()) {
            freq_order.erase(freq_order.find({-freq[x], x}));
        }
        freq[x]++;
        freq_order.insert({-freq[x], x});

        // Median
        if (low.empty() || x <= *low.rbegin()) {
            low.insert(x);
        } else {
            high.insert(x);
        }
        balance();
    }

    void remove(int x) {
        count--;
        sum = (sum - x + MOD) % MOD;
        sumsq = (sumsq - (x * 1LL * x) % MOD + MOD) % MOD;

        // Mode
        if (freq_order.find({-freq[x], x}) != freq_order.end()) {
            freq_order.erase(freq_order.find({-freq[x], x}));
        }
        freq[x]--;
        if (freq[x] > 0) {
            freq_order.insert({-freq[x], x});
        }

        // Median
        if (high.find(x) != high.end()) {
            high.erase(high.find(x));
        } else {
            low.erase(low.find(x));
        }
        balance();
    }

    int mean() const {
        if (count == 0) return -1;
        return (sum * 1LL * binpow(count, MOD - 2, MOD)) % MOD;
    }

    int variance() const {
        if (count == 0) return -1;
        int mean_val = mean();
        return (sumsq - (count * 1LL * mean_val * mean_val % MOD) + MOD) % MOD;
    }

    int mode() const {
        if (count == 0) return -1;
        return freq_order.begin()->second;
    }

    int median() const {
        if (count == 0) return -1;
        if (count % 2 == 1) {
            return *low.rbegin();
        } else {
            return bin_div(*low.rbegin() + *high.begin(), 2);
        }
    }
};

void solve() {
    DataDashboard ddb;

    int n;
    cin >> n;

    string cmd;
    for (int i = 0; i < n; ++i) {
        cin >> cmd;
        if (cmd == "insert") {
            int x;
            cin >> x;
            ddb.insert(x);
        } else if (cmd == "remove") {
            int x;
            cin >> x;
            ddb.remove(x);
        } else if (cmd == "getMean") {
            cout << ddb.mean() << "\n";
        } else if (cmd == "getMedian") {
            cout << ddb.median() << "\n";
        } else if (cmd == "getMode") {
            cout << ddb.mode() << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
