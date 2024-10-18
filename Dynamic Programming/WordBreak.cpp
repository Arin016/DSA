#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
string s;
map<string, int> mp;
vector<int> dp;

int rec(int level) {
    // Base case
    if(level == s.length()) return 1;

    // Check if the value is already computed
    if(dp[level] != -1) return dp[level];

    // Compute result
    int ans = 0;
    string temp = "";
    
    for(int i = level; i < s.length(); i++) {
        temp += s[i];
        if(mp.count(temp)) {
            ans = (ans + rec(i + 1)) % mod;
        }
    }
    
    // Store the result in the dp array and return
    return dp[level] = ans;
}

void solve() {
    cin >> n >> s;
    mp.clear();  // Clear the map for each test case
    dp.assign(s.length(), -1);  // Initialize dp with -1 (uncomputed state)
    
    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        mp[temp]++;
    }

    // Call recursion and check the result
    if(rec(0) > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
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
}
