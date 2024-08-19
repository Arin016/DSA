#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

// Find the longest subsequence where alternate values shouldn't differ by more than D.

int n, D, arr[1000100];
map<int, int> cc;

struct Node {
    int x;
    Node(int xx = 0) {
        x = xx;
    }
};

Node merge(Node a, Node b) {
    Node ans;
    ans.x = max(a.x, b.x);
    return ans;
}

struct segTree {
    vector<Node> tree;
    vector<int> a;

    void init(int n, vector<int> arr) {
        tree.resize(4 * n + 400);
        a = vector<int>(n + 100, 0);
    }

    void build(int index, int l, int r) {
        if (l == r) {
            tree[index] = Node(0);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * index, l, mid);
        build(2 * index + 1, mid + 1, r);
        tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
    }

    void update(int index, int l, int r, int pos, int val) {
        if (pos < l || pos > r) return;
        if (l == r) {
            a[pos] = max(a[pos], val);
            tree[index] = Node(a[pos]);
            return;
        }
        int mid = (l + r) / 2;
        update(2 * index, l, mid, pos, val);
        update(2 * index + 1, mid + 1, r, pos, val);
        tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
    }

    Node query(int index, int l, int r, int lq, int rq) {
        if (l > rq || r < lq) return Node();
        if (l >= lq && r <= rq) {
            return tree[index];
        }
        int mid = (l + r) / 2;
        return merge(query(2 * index, l, mid, lq, rq), query(2 * index + 1, mid + 1, r, lq, rq));
    }
};

void solve() {
    cin >> n >> D;
    for (int i = 0; i < n; i++) cin >> arr[i], cc[arr[i]];

    int cnt = 0;
    for (auto &x : cc) {
        x.second = cnt++;
    }
    segTree st;
    st.init(2e5, vector<int>(2e5, 0));
    st.build(1, 0, 2e5 - 1);
    // x = regular value
    // mp[x] = compressed value
    int ans = 0;
    for(int i = 0; i < n; i++){
        int lo = arr[i] - D;  // These are original values and not the compressed values
        int hi = arr[i] + D;  // These are original values.

        auto it = cc.upper_bound(hi);
        if (it != cc.begin()) --it;
        hi = it->second; // Now this is compressed values in segtree as hi now stores the compressed value.

        it = cc.lower_bound(lo);
        lo = it->second;

        int best = st.query(1, 0, 2e5 - 1, lo, hi).x + 1;
        ans = max(ans, best);
        st.update(1, 0, 2e5 - 1, cc[arr[i]], best);
    }

    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        cc.clear(); // Clear the compression map for each test case.
        solve();
    }
}
