#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Node {
    vector<int> arr;
    Node(vector<int> temp = {}) {
        arr = temp;
    }
};

Node merge(Node a, Node b){
    Node ans;
    for(auto x:a.arr){
        ans.arr.push_back(x);
    }
    for(auto x:b.arr){
        ans.arr.push_back(x);
    }
    sort(ans.arr.begin(), ans.arr.end());
    return ans;
}

struct segTree {
    vector<Node> tree;
    vector<int> a;

    void init(int n, const vector<int> &arr) {
        a = arr;
        tree.resize(4 * n + 10);
    }

    void build(int index, int l, int r) {
        if (l == r) {
            tree[index] = Node({a[l]});
            return;
        }
        int mid = (l + r) / 2;
        build(2 * index, l, mid);
        build(2 * index + 1, mid + 1, r);
        tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
    }

    void update(int index, int l, int r, int pos, int val){
        if(pos<l||pos>r)return;
        if(l==r){
            a[l] = val;
            tree[index] = Node({a[l]});
            return; 
        }
        int mid = (l + r) / 2;
        update(2 * index, l, mid, pos, val);
        update(2 * index + 1, mid + 1, r, pos, val);
        tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
    }

    Node query(int index, int l, int r, int lq, int rq) {
        if (r < lq || l > rq) return Node();
        if (l >= lq && r <= rq) {
            return tree[index];
        }
        int mid = (l + r) / 2;
        return merge(query(2 * index, l, mid, lq, rq), query(2 * index + 1, mid + 1, r, lq, rq));
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    segTree st;
    st.init(n, a);
    st.build(1, 0, n - 1);

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        l--, r--;
        Node res = st.query(1, 0, n - 1, l, r);
        cout << res.arr[k - 1] << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
