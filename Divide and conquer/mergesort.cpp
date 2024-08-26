#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int inversioncnt;

struct Node{
    vector<int> arr;
    Node(vector<int> aa = {}){
        arr = aa;
    }
};

Node merge(Node a, Node b) {
    Node c;
    c.arr.resize(a.arr.size() + b.arr.size());
    int i = 0, j = 0, k = 0;
    while (i < a.arr.size() && j < b.arr.size()) {
        if (a.arr[i] <= b.arr[j]) {
            c.arr[k++] = a.arr[i++];
        } else {
            inversioncnt+=(a.arr.size()-i);
            c.arr[k++] = b.arr[j++];
        }
    }
    while (i < a.arr.size()) {
        c.arr[k++] = a.arr[i++];
    }
    while (j < b.arr.size()) {
        c.arr[k++] = b.arr[j++];
    }
    return c;
}

struct segTree {
    vector<Node> tree;
    vector<int> a;

    void init(int n, vector<int> arr) {
        tree.resize(4 * n);
        a = arr;
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
};


void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    inversioncnt = 0;
    for (int i = 0; i < n; i++) cin >> arr[i];
    segTree st;
    st.init(n, arr);
    st.build(1, 0, n - 1);
    // Further processing can be done here
    cout<<inversioncnt<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}