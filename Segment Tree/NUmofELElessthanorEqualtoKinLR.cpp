#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
#define F first
#define S second

struct Node{
    int x;
    Node(int xx=0){
        x = xx;
    }
};

Node merge(Node a, Node b){
    Node ans;
    ans.x = a.x+b.x;
    return ans;

}

struct segTree{
    vector<Node> tree;
    vector<int> a;

    void init(int n, vector<int> arr){
        tree.resize(4*n+400);
        a.resize(n+100);
        a = arr;
    }

    void build(int index, int l, int r){
        if(l==r){
            tree[index] = Node();
            return; 
        }
        int mid = (l+r)/2;
        build(2*index, l, mid);
        build(2*index, mid+1, r);
        tree[index] = merge(tree[2*index], tree[2*index+1]);
    }
    //this is nlogn(merge)*logn(# of nodes) update
    //use indexed set for better complexity
    void update(int index, int l, int r, int pos, int val) {
        if (pos < l || pos > r) return;
        if (l == r) {
            a[pos] = 1;
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

void solve(){
    int n, q;
    cin>>n>>q;
    vector<int> arr;
    vector<pair<int, int>> v;
    for(int i=0;i<n;i++)cin>>arr[i], v.push_back({arr[i], i});
    sort(v.begin(), v.end());
    vector<pair<pair<int, int>, pair<int, int>>> queries;
    for(int i=0;i<q;i++){
        int l, r, k;
        cin>>l>>r>>k;
        queries.push_back({{k, i}, {l, r}});
    }
    sort(queries.begin(), queries.end());
    vector<int> ans(q);
    segTree st;
    st.init(n, );
    st.build(1, 0, n-1);
    int pos = 0;
    for(auto x:queries){
        while(pos<v.size() and v[pos].F<=x.F.F){
            st.update(1, 0, n-1, v[pos].S, 1);
            pos++;
        }
        ans[x.F.S] = st.query(1, 0, n-1, x.S.F, x.S.S).x;
    }
    for(auto x:ans){
        cout<<x<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
