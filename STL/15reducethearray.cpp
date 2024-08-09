#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

void solve() {
    int n;
    cin >> n;  // Read the value of n
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(-x);  // Push the negative value to simulate a min-heap
    }
    int ans = 0;
    while (pq.size() > 1) {
        int temp1 = -pq.top();
        pq.pop();
        int temp2 = -pq.top();
        pq.pop();
        ans += temp1 + temp2;
        pq.push(-(temp1 + temp2));
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
