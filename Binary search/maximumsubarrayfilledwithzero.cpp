#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;

int n, x, y;
int a[1000100];

bool check(int mid) {

    multiset<int> m1, m2;
    int k = mid - y;
    int sum = 0;

    for (int i = 0; i < mid; i++) {
        m2.insert(a[i]);
    }

    int cnt = 0;
    for (auto it = m2.begin(); it != m2.end() && cnt < k; it++, cnt++) {
        m1.insert(*it);
        sum += *it;
    }

    for (auto it = m1.begin(); it != m1.end(); it++) {
        m2.erase(m2.find(*it));
    }

    if (sum <= x) return true;

    int l = 0, r = mid;
    while (r < n) {
        // exclude l
        if (m1.count(a[l])) {
            m1.erase(m1.find(a[l]));
            sum -= a[l];

            if (!m2.empty()) {
                m1.insert(*m2.begin());
                sum += *m2.begin();
                m2.erase(m2.begin());
            }
        } else {
            m2.erase(m2.find(a[l]));
        }

        l++;

        // include r
        if (m1.size() < k) {
            sum += a[r];
            m1.insert(a[r]);
        } else {
            if (a[r] < *m1.rbegin()) {
                sum += a[r];
                sum -= *m1.rbegin();
                m2.insert(*m1.rbegin());
                m1.erase(--m1.end());
                m1.insert(a[r]);
            } else {
                m2.insert(a[r]);
            }
        }
        r++;

        if (sum <= x) return true;
    }

    return false;
}

void solve() {
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++) cin >> a[i];

    int lo = y, hi = n, ans = y;
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
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
