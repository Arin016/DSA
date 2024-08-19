#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

//kth segtree
//node tells me how many element in the array in range l..r exists

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
            tree[index] = Node(1);
            return;
        }
        int mid = (l+r)/2;
        build(2*index, l, mid);
        build(2*index+1, mid+1, r);
        tree[index] = merge(tree[2*index], tree[2*index+1]);
    }
    //yeh merko kth smallest position update karke dega and not kth position 
    void update(int index, int l, int r, int i, int val){
        if(l==r){ //leaf node
            tree[index] = Node(val);
            return;
        }
        int mid = (l+r)/2;
        //how are you going to reach to the correct leaf??
        if(i<=tree[2*index].x) update(2*index, l, mid, i, val);
        else update(2*index+1, mid+1, r, i-tree[2*index].x, val);
        tree[index] = merge(tree[2*index], tree[2*index+1]);
    }

    int findkth(int index, int l, int r, int k){
        if(l==r){
            return a[l];
        }
        int mid = (l+r)/2;
        if(k<=tree[2*index].x)return findkth(2*index, l, mid, k);
        else return findkth(2*index+1, mid+1, r, k-tree[2*index].x);
    }

};

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    segTree st;
    st.init(n, arr);
    st.build(1, 0, n-1);
    int q;
    q = n;
    while(q--){
        int p;
        cin>>p;
        cout<<st.findkth(1, 0, n-1, p)<<" ";
        st.update(1, 0, n-1, p, 0);
    }
    cout<<endl;

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
