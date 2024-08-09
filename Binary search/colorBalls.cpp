#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k;
vector<int> a;
unordered_map<int, int> f;

bool check(int mid) {
    int cnt = 0, sum = 0;
    for (auto x : f) {
        if (x.second >= mid) {
            cnt++;
        } else {
            sum += x.second;
        }
    }
    cnt += (sum / mid);
    return cnt >= k;
}

void solve() {
    cin >> n >> k;
    a.resize(n);
    f.clear();
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[a[i]]++;
    }

    int lo = 1, hi = n, ans = 0; //you cant set lo = 0 because in check mid is in denominator and itd give a runtime error
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
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

    return 0;
}
