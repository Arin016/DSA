#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

vector<int> prevsmaller(int* a, int n) {
    vector<int> ans(n);
    stack<int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() and a[st.top()] >= a[i]) st.pop();
        if(!st.empty()) ans[i] = st.top();
        else ans[i] = -1;
        st.push(i);
    }
    return ans;
}

vector<int> nextsmaller(int* a, int n) {
    vector<int> ans(n);
    stack<int> st;
    for(int i = n-1; i >= 0; i--) {
        while(!st.empty() and a[st.top()] >= a[i]) st.pop();
        if(!st.empty()) ans[i] = st.top();
        else ans[i] = n;
        st.push(i);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    
    int h[n+1];
    for(int i = 0; i <= n; i++) h[i] = -1e9;
    
    vector<int> prevsm = prevsmaller(a, n);
    vector<int> nextsm = nextsmaller(a, n);
    
    for(int i = 0; i < n; i++) {
        int currlen = (nextsm[i] - prevsm[i] - 1);
        h[currlen] = max(h[currlen], a[i]);
    }
    
    for(int i = n-1; i >= 1; i--) {
        h[i] = max(h[i], h[i+1]);
    }
    
    for(int i = 1; i <= n; i++) {
        cout << h[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
