#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define int long long 

using event = pair<pair<int, int>, pair<int, int>>;

void solve() {
    int n;
    cin >> n;
    vector<event> events;
    for (int i = 0; i < n; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        events.push_back({{l, 0}, {x, i}});
        events.push_back({{r, 2}, {x, i}});
    }

    //note that you have to maintain the order {{event_index, event_type}, {value, index}}
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int y, z;
        cin >> y >> z;
        events.push_back({{y, 1}, {z, i}});
    }
    sort(events.begin(), events.end());
    multiset<int> mt;
    vector<int> ans(q);
    for (int i = 0; i < events.size(); i++) {
        if (events[i].F.S == 0) {
            // insert
            mt.insert(events[i].S.F);
        } else if (events[i].F.S == 1) {
            // query
            auto it = mt.upper_bound(events[i].S.F);
            if (it != mt.begin()) {
                it--;
                ans[events[i].S.S] = *it;
            } else {
                ans[events[i].S.S] = -1;
            }
        } else {
            // remove
            mt.erase(mt.find(events[i].S.F));
        }
    }

    for (auto v : ans) {
        cout << v << endl;
    }
    return;
}

signed main() {
    solve();
    return 0;
}