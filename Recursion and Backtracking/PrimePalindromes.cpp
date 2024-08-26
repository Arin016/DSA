#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int a, b;
string s;

bool is_prime(int x) {
    if (x <= 1) return false;
    if (x <= 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;
    for (int i = 5; i * i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) return false;
    }
    return true;
}

int rec(int level) {
    if (level == 5) {
        int x = stoll(s);
        string str = to_string(x);
        string tempstr1 = str;
        string tempstr2 = str;
        reverse(str.begin(),str.end());
        tempstr1 += str;
        tempstr2 += str.substr(1);
        //cout<<tempstr<<endl;
        int y1 = stoll(tempstr1);//even len
        int y2 = stoll(tempstr2);//odd len
        int fans = 0;
        if (y1 >= a && y1 <= b && is_prime(y1)) {
            fans++;
        }
        if (y2 >= a && y2 <= b && is_prime(y2)) {
            fans++;
        }
        return fans;
    }

    int ans = 0;

    for (int i = 0; i <= 9; i++) {
        s += to_string(i);
        ans += rec(level + 1);
        s.pop_back();
    }
    return ans;
}

void solve() {
    cin >> a >> b;
    cout << rec(0) << endl;
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