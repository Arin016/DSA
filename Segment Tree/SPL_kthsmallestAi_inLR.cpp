#include <bits/stdc++.h>
using namespace std;
#define int long long


//what is the kth smallest ai in l....r?
//BS on ans for each query

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

    int query(int index, int l, int r, int lq, int rq, int val) {
        if (r < lq || l > rq) return 0;
        if (l >= lq && r <= rq) {
            //is range (l...r) mein kitne elements hai joh <= val hai --> Upper bound
            //number of ele <= val in a sorted array
            vector<int> &a = tree[index].arr;
            auto it = upper_bound(a.begin(), a.end(), val) - a.begin();
            return it;
        }
        int mid = (l + r) / 2;
        return query(2 * index, l, mid, lq, rq, val) + query(2 * index + 1, mid + 1, r, lq, rq, val);
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
        int lo = 1;
        int hi = 1e9;
        int ans = lo;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            //(#of ele<=mid)>=k then mid is a possible ans
            if(st.query(1, 0, n-1, l, r, mid) >= k){
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        cout << ans << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
