#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

//we have seen point update range query till now
//for range update point query
// 1 l r u and 2 x
//use the Pt updtae range query code and
//1 l r u --> 2 i==l val+=u, 2 i==r+1 val-=u 
//2 x --> 1 l==0 r==x

struct Node{
    int cnt;
    Node(int xx=0){
        cnt = xx;
    }
};

Node merge(Node a, Node b){
    Node ans;
    ans.cnt = a.cnt+b.cnt;
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
            tree[index] = Node(a[l] % 2);  // store 1 if odd, 0 if even
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
            tree[index] = Node(x % 2);  
            return;
        }
        int mid = (l + r) / 2;
        update(2 * index, l, mid, i, x);
        update(2 * index + 1, mid + 1, r, i, x);
        tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
    }

    // Query returns number of odd numbers in the range
    Node query(int index, int l, int r, int lq, int rq){
        if(r < lq || l > rq) return Node(0);
        if(lq <= l && r <= rq){
            return tree[index];
        }
        int mid = (l + r) / 2;
        return merge(query(2 * index, l, mid, lq, rq), query(2 * index + 1, mid + 1, r, lq, rq));
    }
};

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    SegTree st;
    st.init(n, arr);
    st.build(1, 0, n - 1);
    
    int q;
    cin >> q;
    while(q--){
        int ch;
        cin >> ch;
        if(ch == 0){
            int x, y;
            cin >> x >> y;
            x--;
            st.update(1, 0, n - 1, x, y);
        } else if(ch == 1){
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << (r - l + 1) - st.query(1, 0, n - 1, l, r).cnt << endl;
        }
        else{
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout <<st.query(1, 0, n - 1, l, r).cnt << endl;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
