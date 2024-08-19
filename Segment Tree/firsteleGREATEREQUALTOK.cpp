#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
int a[200100]; 
int t[800400]; 

void build(int index, int l, int r) {
    if (l == r) {
        t[index] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * index, l, mid);
    build(2 * index + 1, mid + 1, r);
    t[index] = max(t[2 * index], t[2 * index + 1]);
}

void update(int index, int l, int r, int pos, int val) {
    if (l == r) {
        t[index] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        update(2 * index, l, mid, pos, val);
    else
        update(2 * index + 1, mid + 1, r, pos, val);
    t[index] = max(t[2 * index], t[2 * index + 1]);
}
//kth segtree query
//first ele >=val(room)
int query(int index, int l, int r, int room) {
    if (t[index] < room) return -1;
    if (l == r) return l;

    int mid = (l + r) / 2;
    if (t[2 * index] >= room) return query(2 * index, l, mid, room);
    else return query(2 * index + 1, mid + 1, r, room);
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    build(1, 0, n - 1);

    for (int i = 0; i < m; i++) {
        int r;
        cin >> r;
        int idx = query(1, 0, n - 1, r);
        if (idx == -1) {
            cout << 0 << " ";
        } else {
            cout << idx + 1 << " ";
            a[idx] -= r;
            update(1, 0, n - 1, idx, a[idx]);
        }
    }
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
