#include <bits/stdc++.h>
using namespace std;
#define int long long


//if negative numbers exist then you cant use two pointers on sum based approach where in head is moving based on the sum

int n, k, d;
int a[1000100];
int p[1000100];

void solve() {
    cin >> n >> k >> d;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[i] = a[i];
        if (i) p[i] += p[i - 1];
    }

    int head = -1, tail = 0;
    int ans = -1e18;
    multiset<int> ms; //can have duplicates too in sorted order, supports add remove UB LB
    int ocnt = 0;
    //use two pointers to move according to one condition and cnt for the ans using the other condition
    while (tail < n) {
        while (head + 1 < n && ((ocnt + (abs(a[head + 1]) % 2) <= k))) {
            head++;
            ocnt += abs(a[head] % 2);
            ms.insert(p[head]);
        }
        // //when we have a valid window and our multiset is ready
        if (!ms.empty()) {
            auto it = ms.upper_bound((tail > 0) ? p[tail - 1] + d : d);
            if (it != ms.begin()) {
                it--;
                int bestr = *it;
                ans = max(ans, bestr - (tail > 0 ? p[tail - 1] : 0));
            }
        }

        if (head >= tail) {
            ms.erase(ms.find(p[tail]));
            ocnt -= abs(a[tail] % 2);
            tail++;
        } else {
            tail++;
            head = tail - 1;
        }
    }

    if (ans == -1e18) cout << "IMPOSSIBLE" << endl;
    else cout << ans << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
