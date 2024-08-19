#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
#define endl '\n' 
 
vector<int> arr;
unordered_map<int, int> vals;
vector<int> t;
 
void build(int n) {
    t.resize(4 * n, 0);
}
 
void update(int index, int l, int r, int pos, int val) {
    if (pos < l || pos > r) {
        return;
    }
 
    if (l == r) {
        t[index] += val;
        return;
    }
 
    int mid = (l + r) / 2;
 
    update(2 * index, l, mid, pos, val);
    update(2 * index + 1, mid + 1, r, pos, val);
 
    t[index] = t[2 * index] + t[2 * index + 1];
}
 
int query(int index, int l, int r, int lq, int rq) {
    if (rq < l || lq > r) {
        return 0;
    }
 
    if (lq <= l && r <= rq) {
        return t[index];
    }
 
    int mid = (l + r) / 2;
 
    return query(2 * index, l, mid, lq, rq) + query(2 * index + 1, mid + 1, r, lq, rq);
}
 
void solve() {
    int n, q;
    cin >> n >> q;
    arr.resize(n);
    vector<int> salaries(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        salaries[i] = arr[i];
    }
 
    vector<pair<char, pair<int, int>>> queries(q);
    for (int i = 0; i < q; i++) {
        char ch;
        cin >> ch;
        if (ch == '!') {
            int k, x;
            cin >> k >> x;
            queries[i] = {ch, {k - 1, x}};
            salaries.push_back(x);
        } else {
            int a, b;
            cin >> a >> b;
            queries[i] = {ch, {a, b}};
            salaries.push_back(a);
            salaries.push_back(b);
        }
    }
 
    sort(salaries.begin(), salaries.end());
    salaries.erase(unique(salaries.begin(), salaries.end()), salaries.end());
 
    for (int i = 0; i < salaries.size(); i++) {
        vals[salaries[i]] = i;
    }
 
    int m = salaries.size();
    build(m);
 
    for (int i = 0; i < n; i++) {
        update(1, 0, m - 1, vals[arr[i]], 1);
    }
 
    for (auto& q : queries) {
        if (q.first == '!') {
            int idx = q.second.first;
            int new_val = q.second.second;
            update(1, 0, m - 1, vals[arr[idx]], -1);
            arr[idx] = new_val;
            update(1, 0, m - 1, vals[new_val], 1);
        } else {
            int a = q.second.first;
            int b = q.second.second;
            cout << query(1, 0, m - 1, vals[a], vals[b]) << endl;
        }
    }
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }

}
