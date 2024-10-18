#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
vector<int> a, dp;

// staring form: best ans starting at level
int rec(int level) {
    // base case
    if (level == n) return 0;
    
    // cache check
    if (dp[level] != -1) return dp[level];

    // compute
    int ans = 1;
    for (int i = level + 1; i < n; i++) {
        if (a[i] > a[level]) {
            ans = max(ans, 1 + rec(i));
        }
    }
    
    // save and return
    return dp[level] = ans;
}

void printsol(int level) {
     // base case
    if (level == n) return;

    // compute
    //catching the right transition
    int ans = rec(level);
    for (int i = level + 1; i < n; i++) {
        if (a[i] > a[level]) {
            if(ans==1+rec(i)){
                cout<<a[i]<<" ";
                printsol(i);
                return; // yeh return marna IMP hai!!!!
            }
        }
    }
}

void solve() {
    cin >> n;
    a.resize(n);
    dp.assign(n, -1);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int LIS = 0, index = -1;

    // Find the longest increasing subsequence (LIS)
    for (int i = 0; i < n; i++) {
        if (rec(i) > LIS) {
            LIS = rec(i);
            index = i;
        }
    }

    // Output the length of the LIS
    cout << LIS << endl;

    // Output the sequence starting from the found index
    cout << a[index] << " "; // print the first element
    printsol(index); // print the remaining LIS sequence
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
