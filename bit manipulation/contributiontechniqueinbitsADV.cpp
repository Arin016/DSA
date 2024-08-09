#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second

const int INF = 1e9+7;
const int MOD = 1e9+7;

typedef pair<int, int> pii;
typedef pair<long, long> pll;

// Function to compute the sum of set bits from 0 to n
int sum_of_bits(int n) {
    int ans = 0;
    int total = n + 1;
    for (int i = 0; i < 60; i++) {
        int full = (total / (1LL << (i + 1))) * (1LL << i);
        int left = total % (1LL << (i + 1));
        int extra = max(left - (1LL << i), 0LL); 
        ans += full + extra;
    }
    return ans;
}

// Function to find the k-th one
int find_kth_one(int k) {
    int lo = 0, hi = k;
    int ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (sum_of_bits(mid) >= k) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

// Function to convert a number to its binary string representation
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

// Function to get the position of the k-th one in the binary representation of a number
int get_kth_one_pos_in_num(int x, int k) {
    int cnt = 0;
    string num = getbitstr(x);
    for (int i = 0; i < num.length(); i++) {
        if (num[i] == '1') {
            cnt++;
        }
        if (cnt == k) {
            return i;
        }
    }
}

// Function to calculate total bits till a number x
int total_bits_till(int x) {
    int ans = 0;
    int len = 1;
    int num = 1;
    while (num <= x) {
        int sametill = (num * 2) - 1;
        if (sametill <= x) {
            ans += len * (sametill - num + 1);
            num = sametill + 1;
            len++;
        } else {
            ans += len * (x - num + 1);
            break;
        }
    }
    return ans+1;
}

// Function to solve the problem for multiple queries
void solve() {
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        int num = find_kth_one(k);
        int pos_in_num = k - sum_of_bits(num - 1);
        int index = get_kth_one_pos_in_num(num, pos_in_num);
        cout << total_bits_till(num - 1) + index<< endl;
    }
}

// Main function
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