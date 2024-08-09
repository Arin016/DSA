#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

struct DataStructure {
    int k;
    multiset<int> ms1, ms2;
    int sumK;

    void init(int _k) {
        k = _k;
        sumK = 0;
        ms1.clear();
        ms2.clear();
    }

    void insert(int x) {
        ms1.insert(x);
        sumK += x;
        if (ms1.size() > k) {
            ms2.insert(*ms1.begin());
            sumK -= *ms1.begin();
            ms1.erase(ms1.begin());
        }
    }

    void erase(int x) {
        if (ms1.find(x) != ms1.end()) {
            sumK -= x;
            ms1.erase(ms1.find(x));
        } else if (ms2.find(x) != ms2.end()) {
            ms2.erase(ms2.find(x));
        }

        if (ms1.size() < k && !ms2.empty()) {
            auto it = --ms2.end();
            ms1.insert(*it);
            sumK += *it;
            ms2.erase(it);
        }
    }

    int print() { return sumK; }
};

void solve() {
    int q, k;
    cin >> q >> k;

    DataStructure ds;
    ds.init(k);
    while (q--) {
        int x;
        cin >> x;
        if (x == 1) {
            int a;
            cin >> a;
            ds.insert(a);
        } else if (x == 2) {
            int a;
            cin >> a;
            ds.erase(a);
        } else if (x == 3) {
            char c;
            cin >> c;
            cout << ds.print() << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
