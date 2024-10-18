#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int n, m;
string a, b;
vector<vector<int>> dp;
int rec(int i, int j){
    // base cases
    if(i == n) {
        return m - j;
    }
    if(j == m) {
        return n - i;
    }
    //cace check
    if(dp[i][j]!=-1)return dp[i][j];
    //compute
    int ans = 1e18;
    //save and return
    if(a[i] == b[j]) {
        ans = min(ans, 1 + rec(i+1, j+1));
    }
    else{
        ans = min(ans, 1+rec(i+1, j));
        ans = min(ans, 1+rec(i, j+1));
    }
    return dp[i][j] = ans;
}

string ans;

void printsol(int i, int j){
    // base cases
    if(i == n){
        while(j < m) {
            ans += b[j++];
        }
        return;
    }
    if(j == m){
        while(i < n) {
            ans += a[i++];
        }
        return;
    }
    // compute
    int curr = rec(i, j);
    if(a[i] == b[j]){
        if(curr == 1+rec(i+1, j+1)){
            ans += a[i];
            printsol(i+1, j+1);
            return;
        }
    }
    else {
        if(curr == 1 + rec(i+1, j)){
            ans += a[i];
            printsol(i+1, j);
            return;
        }
        else {
            ans += b[j];
            printsol(i, j+1);
            return;
        }
    }
}

string ShortestCommonSupersequence(string &str1, string &str2) {
    ans.clear();
    a = str1, b = str2;
    n = a.length(), m = b.length();
    dp.assign(n+1, vector<int>(m+1, -1));
    int gg = rec(0, 0); 
    printsol(0, 0); 
    return ans;
}

void checker() {
    string x, y;
    cin >> x >> y;
    auto s = ShortestCommonSupersequence(x, y);
    //cout << s << endl;
    cout << s.size() << endl;
    
    bool f = 1;
    int i = 0, j = 0;
    while (i < x.size() && j < s.size()) {
        if (x[i] == s[j]) i++, j++;
        else j++;
    }
    if (i != x.size()) f = 0;

    i = 0, j = 0;
    while (i < y.size() && j < s.size()) {
        if (y[i] == s[j]) i++, j++;
        else j++;
    }
    if (i != y.size()) f = 0;

    cout << f << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); 
    cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        checker();
    }
    return 0;
}