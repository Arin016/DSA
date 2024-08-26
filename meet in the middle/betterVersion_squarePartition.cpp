#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
vector<int> arr;
vector<int> part1, part2;

vector<pair<pair<int, int>, pair<int, int>>> abcdposs, pqrsposs;

void recabcd(int level, int a, int b, int c, int d) {
    // base case
    if (level == part1.size()) {
        abcdposs.push_back({{a, b}, {c, d}});
        return;
    }
    // recursive case
    recabcd(level + 1, a + part1[level], b, c, d);
    recabcd(level + 1, a, b + part1[level], c, d);
    recabcd(level + 1, a, b, c + part1[level], d);
    recabcd(level + 1, a, b, c, d + part1[level]);
}

void recpqrs(int level, int p, int q, int r, int s) {
    // base case
    if (level == part2.size()) {
        pqrsposs.push_back({{p, q}, {r, s}});
        return;
    }
    // recursive case
    recpqrs(level + 1, p + part2[level], q, r, s);
    recpqrs(level + 1, p, q + part2[level], r, s);
    recpqrs(level + 1, p, q, r + part2[level], s);
    recpqrs(level + 1, p, q, r, s + part2[level]);
}

void solve() {
    cin >> n;
    arr.resize(n);
    int total = 0;
    part1.clear();
    part2.clear();
    abcdposs.clear();
    pqrsposs.clear();

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        total += arr[i];
        if (i % 2 == 0) part1.push_back(arr[i]);
        else part2.push_back(arr[i]);
    }

    recabcd(0, 0, 0, 0, 0);
    recpqrs(0, 0, 0, 0, 0);

    if (total % 4 != 0) {
        cout << "NO" << endl;
        return;
    }

    int val = total / 4;
    unordered_set<string> pqrsSet;

    for (auto &x : pqrsposs) {
        string key = to_string(x.first.first) + "," + to_string(x.first.second) + "," + to_string(x.second.first) + "," + to_string(x.second.second);
        pqrsSet.insert(key);
    }

    for (auto &x : abcdposs) {
        string key = to_string(val - x.first.first) + "," + to_string(val - x.first.second) + "," + to_string(val - x.second.first) + "," + to_string(val - x.second.second);
        if (pqrsSet.find(key) != pqrsSet.end()) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
