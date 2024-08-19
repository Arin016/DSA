#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

struct Node{
    int psum, totsum;
    Node(int mm = 0, int tt = 0){
        psum = mm;
        totsum = tt;
    }
};

Node merge(Node a, Node b){
    Node ans;
    ans.psum = max({a.psum, a.totsum+b.psum});
    ans.totsum = a.totsum+b.totsum;
    return ans;
}

//      c
//     / \
//    a   b



struct SegTree{
    vector<Node> tree;
    vector<int> a;

    void init(int n, vector<int> arr){
        a = arr;
        tree.resize(4 * n);
    }

    void build(int index, int l, int r){
        if(l == r){
            tree[index] = Node(max(0LL, a[l]), a[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * index, l, mid);
        build(2 * index + 1, mid + 1, r);
        tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
    }

    void update(int index, int l, int r, int i, int x){
        if(i<l||i<r)return;
        if(l == r){
            a[l] = x;
            tree[index] = Node(max(0LL, a[l]), a[l]);
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
        int ch;
        cin>>ch;
        if(ch==1){
            int k, u;
            cin>>k>>u;
            k--;
            st.update(1, 0, n-1, k, u);
        }
        else if(ch==2){
            int a, b;
            cin>>a>>b;
            a--, b--;
            cout<<st.query(1, 0, n-1, a, b).psum<<endl;
        }
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
