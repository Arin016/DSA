#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

struct Node {
    int maxlen, open, close;
    Node(int ml = 0, int op = 0, int cc = 0) {
        maxlen = ml;
        open = op;
        close = cc;
    }
};

//    c
//   / \
//  a   b

Node merge(Node a, Node b) {
    Node ans;
    int matched = min(a.open, b.close);
    ans.maxlen = a.maxlen + b.maxlen + 2 * matched;
    ans.open = a.open + b.open - matched;
    ans.close = a.close + b.close - matched;
    return ans;
}

struct SegTree {
    vector<Node> tree;
    vector<int> a;

    void init(int n, const vector<int>& arr) {
        a = arr;
        tree.resize(4 * n);
    }

    void build(int index, int l, int r) {
        if (l == r) {
            tree[index] = Node(0, (a[l] == 1) ? 1 : 0, (a[l] == -1) ? 1 : 0);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * index, l, mid);
        build(2 * index + 1, mid + 1, r);
        tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
    }

    void update(int index, int l, int r, int i, int x) {
        if (i < l || i > r) return;
        if (l == r) {
            a[l] = x;
            tree[index] = Node(0, (a[l] == 1) ? 1 : 0, (a[l] == -1) ? 1 : 0);
            return;
        }
        int mid = (l + r) / 2;
        update(2 * index, l, mid, i, x);
        update(2 * index + 1, mid + 1, r, i, x);
        tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
    }

    Node query(int index, int l, int r, int lq, int rq) {
        if (r < lq || l > rq) return Node();
        if (lq <= l && r <= rq) {
            return tree[index];
        }
        int mid = (l + r) / 2;
        return merge(query(2 * index, l, mid, lq, rq), query(2 * index + 1, mid + 1, r, lq, rq));
    }
};

void solve() {
    int n, q;
    string s;
    cin >> s;
    n = s.length();
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = (s[i] == '(') ? 1 : -1;
    }
    cin >> q;
    SegTree st;
    st.init(n, arr);
    st.build(1, 0, n - 1);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << st.query(1, 0, n - 1, l, r).maxlen << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
