#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;

struct bag {
    int sum = 0;
    map<int, int> mp;

    void add(int x) {
        sum += x;
        mp[x]++;
    }

    void remove(int x) {
        if (mp.find(x) != mp.end()) {
            sum -= x;
            mp[x]--;
            if (mp[x] == 0) {
                mp.erase(x);
            }
        }
    }

    int minp() {
        if (!mp.empty()) {
            return (*mp.begin()).first;
        }
        return -1;
    }

    int maxp() {
        if (!mp.empty()) {
            return (*mp.rbegin()).first;
        }
        return -1;
    }

    int sump() {
        return sum;
    }
};

void solve() {
    int q;
    cin >> q;
    bag b;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            b.add(x);
        } else if (type == 2) {
            int x;
            cin >> x;
            b.remove(x);
        } else if (type == 3) {
            char c;
            cin>>c;
            cout << b.minp() << endl;
        } else if (type == 4) {
            char c;
            cin>>c;
            cout << b.maxp() << endl;
        } else if (type == 5) {
            char c;
            cin>>c;
            cout << b.sump() << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
