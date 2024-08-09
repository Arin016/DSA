#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> prevsmaller(int* a, int n) {
    vector<int> ans(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (!st.empty()) ans[i] = st.top()+1;
        else ans[i] = -1+1;
        st.push(i);
    }
    return ans;
}

vector<int> nextsmaller(int* a, int n) {
    vector<int> ans(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (!st.empty()) ans[i] = st.top()-1;
        else ans[i] = n-1;
        st.push(i);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> prevsm = prevsmaller(a, n);
    vector<int> nextsm = nextsmaller(a, n);

    int maxi = 0;
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, a[i] * ((nextsm[i]) - (prevsm[i]) + 1));
    }

    cout << maxi << endl;
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
