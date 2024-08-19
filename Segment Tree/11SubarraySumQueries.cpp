#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

struct Node{
    int msum, Rsum, Lsum, totsum;
    Node(int mm = 0, int ll = 0, int rr = 0, int tt = 0){
        msum = mm;
        Rsum = ll;
        Lsum = rr;
        totsum = tt;
    }
};

//      c
//     / \
//    a   b

Node merge(Node a, Node b){
    Node ans;
    ans.msum = max({a.msum, b.msum, a.Lsum+b.Rsum});
    ans.Rsum = max({a.Rsum, a.totsum+b.Rsum});
    ans.Lsum = max({b.Lsum, b.totsum+a.Lsum});
    ans.totsum = a.totsum+b.totsum;
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
            tree[index] = Node(max(0LL, a[l]), max(0LL, a[l]), max(0LL, a[l]),a[l]);
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
            tree[index] = Node(max(0LL, a[l]), max(0LL, a[l]), max(0LL, a[l]),a[l]);
            return;
        }
        int mid = (l + r) / 2;
        update(2 * index, l, mid, i, x);
        update(2 * index + 1, mid + 1, r, i, x);
        tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
    }

    Node query(int index, int l, int r, int lq, int rq){
        if(r < lq || l > rq) return Node();
        if(lq <= l && r <= rq){
            return tree[index];
        }
        int mid = (l + r) / 2;
        return merge(query(2 * index, l, mid, lq, rq), query(2 * index + 1, mid + 1, r, lq, rq));
    }
};


void solve(){
    int n, q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    SegTree st;
    st.init(n, arr);
    st.build(1, 0, n-1);
    while(q--){
        int pos, val;
        cin>>pos>>val;
        pos--;
        st.update(1, 0, n-1, pos, val);
        cout<<st.query(1, 0, n-1, 0, n-1).msum<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
