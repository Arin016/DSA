#include <bits/stdc++.h>
using namespace std;
#define int long long

// EULER TOUR!
//update and query on subtree --> EULER TOUR!
// range = output of above code!
// range length = 2*subtreesz
// child range always in parent range
// the vertical line from any point cuts the ancestors!
 
// number the nodes 1......lah lah lah
// calculate for each node the intimer and outtimer which would be first and last timer they were seen in the array
// and computations become easier
 
// queries:
// ? x: what is the value encompassed in subtree of x
// ! x y: update value of node x to y
 
// create another same array where you put value of node at intimer and 0 at outtimer
 
// queries:
// ? x: what is the value encompassed in subtree of x
// ! x y: update value of node x to y
// arr1 --> (intimer = val, outtimer = 0)
 
// queries:
// ? x: what is the value encompassed in path from root to x
// ! x y: update value of node x to y
// arr2 --> (intimer = val, outtimer = -val)
 
struct Node {
    int x;
    Node(int xx = 0) {
        x = xx;
    }
};
 
Node merge(Node a, Node b) {
    Node ans;
    ans.x = a.x + b.x;
    return ans;
}
 
struct SegTree {
    vector<Node> tree;
    vector<int> a;
 
    SegTree(int n = 0, vector<int> arr = {}) {
        tree.resize(4 * n + 400);
        a.resize(n + 100);
        a = arr;
    }
 
    void build(int index, int l, int r) {
        if (l == r) {
            tree[index] = Node(a[l]);
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
            a[pos] = val;
            tree[index] = Node(a[pos]);
            return;
        }
        int mid = (l + r) / 2;
        update(2 * index, l, mid, pos, val);
        update(2 * index + 1, mid + 1, r, pos, val);
        tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
    }
 
    Node query(int index, int l, int r, int lq, int rq) {
        if (r < lq || l > rq) return Node(0);
        if (l >= lq && r <= rq) {
            return tree[index];
        }
        int mid = (l + r) / 2;
        return merge(query(2 * index, l, mid, lq, rq), query(2 * index + 1, mid + 1, r, lq, rq));
    }
};
 
int n, q;
vector<vector<int>> g;
vector<int> val;
vector<int> et;
map<int, pair<int, int>> nodeTime;
 
void dfs(int node, int par) {
    et.push_back(node);
    for (auto x : g[node]) {
        if (x != par) {
            dfs(x, node);
        }
    }
    et.push_back(node);
}
 
void solve() {
    cin >> n >> q;
    g.resize(n + 1);
    val.resize(n + 1);
 
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
 
    dfs(1, -1); // Call DFS to populate et array
 
    // for(auto x:et){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
 
    n = et.size();
    for (int i = 0; i < n; i++) {
        if (nodeTime.count(et[i])==0) {
            nodeTime[et[i]].first = i;
        } else {
            nodeTime[et[i]].second = i;
        }
    }
    // for(auto x:nodeTime){
    //     cout<<x.first<<" : ";
    //     cout<<x.second.first<<" "<<x.second.second<<" ";
    //     cout<<endl;
    // }
    vector<int> arr1(n), arr2(n);
    for (auto x : nodeTime) {
        arr1[x.second.first] = val[x.first];
        arr1[x.second.second] = 0;
        // arr2[x.second.first] = val[x.first];
        // arr2[x.second.second] = -val[x.first];
    }
    // for(auto x:arr1){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    SegTree st1(n, arr1), st2(n, arr2);
    st1.build(1, 0, n - 1);
    st2.build(1, 0, n - 1);
 
    while (q--) {
        int type, x, y;
        cin >> type >> x;
        if (type == 2) {
            cout << st1.query(1, 0, n - 1, nodeTime[x].first, nodeTime[x].second).x << endl;
        } else if (type == 1) {
            cin >> y;
            st1.update(1, 0, n - 1, nodeTime[x].first, y);
        }
    }
}
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}