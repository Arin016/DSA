/*
Given An infinite string: S = "011011100101110111100010011010..."
this is the binary rep of numbers 0,1,2,3,4.... concatenated in a string
q queries: of the form ?k => you have to find the index of the k-th 1 in this string
*/


#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

string getbitstr(int x) {
    string cur = "";
    if (x == 0) return "0";
    while (x) {
        if (x % 2) {
            cur += "1";
        } else {
            cur += "0";
        }
        x /= 2;
    }
    reverse(cur.begin(), cur.end());
    return cur;
}

void solve() {
    string s = "";
    int cnt_one = 0;
    int cur_num = 0;
    while (cnt_one <= 100000) {
        string cur_bits = getbitstr(cur_num);
        int new_one = 0;
        for (auto v : cur_bits) {
            if (v == '1') {
                new_one++;
            }
        }
        s += cur_bits;
        cnt_one += new_one;
        cur_num++;
    }

    vector<int> pos1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            pos1.push_back(i);
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        if (k - 1 >= 0 && k - 1 < pos1.size()) {
            cout << pos1[k - 1] << endl;
        } else {
            cout << -1 << endl; 
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}