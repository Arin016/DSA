#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;


//1 : toggle element
//2 : # of elements <= k

struct Node {
    int x;
    Node(int xx = 0) : x(xx) {}
};

Node merge(Node a, Node b) {
    Node ans;
    ans.x = a.x + b.x;
    return ans;
}

struct segTree {
    vector<Node> tree;
    vector<int> a;

    void init(int n, vector<int> arr) {
        tree.resize(4 * n + 400);
        a.resize(n + 100);
        a = arr;
    }

    void build(int index, int l, int r) {
        if (l == r) {
            tree[index] = Node(0); // Initialize nodes
        } else {
            int mid = (l + r) / 2;
            build(2 * index, l, mid);
            build(2 * index + 1, mid + 1, r);
            tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
        }
    }

    void update(int index, int l, int r, int pos) {
        if (pos < l || pos > r) return;
        if (l == r) {
            tree[index] = Node(a[l]^1); // Toggle the value
        } else {
            int mid = (l + r) / 2;
            update(2 * index, l, mid, pos);
            update(2 * index + 1, mid + 1, r, pos);
            tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
        }
    }

    int query(int index, int l, int r, int k) {
        if (k < l) return 0;
        if (k >= r) return tree[index].x;
        int mid = (l + r) / 2;
        return query(2 * index, l, mid, k) + query(2 * index + 1, mid + 1, r, k);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    map<int, int> mp;
    int i = 0;
    segTree st;
    st.init(2e5, vector<int>(2e5, 0));
    st.build(1, 0, 2e5 - 1);
    vector<pair<int, int>> queries;
    for(int i=0;i<q;i++){
        int x, y;
        cin>>x>>y;
        queries.push_back({x, y});
    }
    vector<int> temp;
    for(auto x:queries){
        temp.push_back(x.second);
    }
    sort(temp.begin(), temp.end());
    for(auto x:temp){
        if(mp.count(x)==0)mp[x] = i++;
    }

    //x = regular value
    //mp[x] = value in segtree

    for(auto x:queries){
        if(x.first==1){
            st.update(1, 0, 2e5-1, mp[x.second]);
        }
        else{
            cout<<st.query(1, 0, 2e5-1, mp[x.second])<<endl;
        }
    }

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
