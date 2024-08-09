#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

struct bag {
    deque<int> lo, hi;

    void balance() {
        while(lo.size() > hi.size() + 1) {
            hi.push_front(lo.back());
            lo.pop_back();
        }
        while(lo.size() < hi.size()) {
            lo.push_back(hi.front());
            hi.pop_front();
        }
    }

    void push_front(int val) {
        lo.push_front(val);
        balance();
    }

    void push_middle(int val) {
        if(lo.size() > hi.size()) {
            hi.push_front(lo.back());
            lo.pop_back();
        }
        lo.push_back(val);
        balance();
    }

    void push_back(int val) {
        hi.push_back(val);
        balance();
    }

    int pop_front() {
        if(lo.empty() && hi.empty()) return -1;
        int ans = lo.front();
        lo.pop_front();
        balance();
        return ans;
    }

    int pop_middle() {
        if(lo.empty() && hi.empty()) return -1;
        int ans = lo.back();
        lo.pop_back();
        balance();
        return ans;
    }

    int pop_back() {
        if(lo.empty() && hi.empty()) return -1;
        int ans;
        if(hi.empty()) {
            ans = lo.back();
            lo.pop_back();
        } else {
            ans = hi.back();
            hi.pop_back();
        }
        balance();
        return ans;
    }
};

void solve() {
   int q;
   cin >> q;
   bag bg;
   while(q--) {
    string s;
    cin >> s;
    if(s == "pushFront") {
        int x;
        cin >> x;
        bg.push_front(x);
    } else if(s == "pushMiddle") {
        int x;
        cin >> x;
        bg.push_middle(x);
    } else if(s == "pushBack") {
        int x;
        cin >> x;
        bg.push_back(x);
    } else if(s == "popFront") {
        cout << bg.pop_front() << endl;
    } else if(s == "popMiddle") {
        cout << bg.pop_middle() << endl;
    } else if(s == "popBack") {
        cout << bg.pop_back() << endl;
    }
   }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
}