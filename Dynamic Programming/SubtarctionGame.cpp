#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
vector<int> dp;

int rec(int x) {
    // Base case: If x is 0, it is a losing state
    if (x == 0) return 0;

    // Cache check
    if (dp[x] != -1) return dp[x];

    // Compute
    int ans = 1;  // Start by assuming it's a winning state

    // Try all transitions (changing each bit one by one)
    for (int i = 0; i <= log2(x); i++) {
        ans &= rec(x  - (1 << i));
    }
    //if the ans still remains 1 after "&" with all possible transitions then that means any state 
    //we transition into from the current state is a winning state, that means our current state is
    //losing state thus we flip the value from 1 to 0
    //if the ans gets to 0 that means there was atleast one losing state that we could transition
    //into that means the current state is indeed a winning state thus flip the value from 0 to 1!
    ans ^= 1;
    // Cache and return the result
    return dp[x] = ans;
}

void solve() {
    cin >> n;
    if (rec(n) == 1) cout << "Vivek" << endl;
    else cout << "Abhishek" << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    dp.assign(2e5 + 101, -1);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
