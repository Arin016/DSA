#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9+7;
//you only have to worry about node and merge logic and leaf value
struct Node{
    int x;
    Node(int mm = 0){
        x = mm;
    }
};

//      c
//     / \
//    a   b

Node merge(Node a, Node b){
    Node ans;
    ans.x = min(a.x, b.x);
    return ans;
}




struct SegTree{
    vector<Node> tree;
    vector<int> a;

    void init(int n, vector<int> arr){
        a = arr;
        tree.resize(4 * n);
    }

    void build(int index, int l, int r){
        if(l == r){
            tree[index] = Node(a[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * index, l, mid);
        build(2 * index + 1, mid + 1, r);
        tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
    }

    void update(int index, int l, int r, int i, int x){
        if(i < l || i > r) return;
        if(l == r){
            a[l] = x;
            tree[index] = Node(a[l]);
            return;
        }
        int mid = (l + r) / 2;
        update(2 * index, l, mid, i, x);
        update(2 * index + 1, mid + 1, r, i, x);
        tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
    }

    Node query(int index, int l, int r, int lq, int rq){
        if(r < lq || l > rq) return Node(1e9);
        if(lq <= l && r <= rq){
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
    for (int i = 0; i < n; i++) cin >> a[i];
    SegTree st;
    st.init(n, a);
    st.build(1, 0, n - 1);
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--; b--;  // 0-based index
        cout << st.query(1, 0, n - 1, a, b).x << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
