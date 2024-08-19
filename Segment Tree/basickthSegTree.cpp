#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

//no of values in set in range l...r is stored in each node

//in all of kth segtree problems the node carries number of relevant numbers in that range

//given a set add x remove x whats the kth ele

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
            tree[index] = Node(0);
            return;
        }
        int mid = (l+r)/2;
        build(2*index, l, mid);
        build(2*index+1, mid+1, r);
        tree[index] = merge(tree[2*index], tree[2*index+1]);
    }
    //update ith position vs update ith smallest position
    void update(int index, int l, int r, int i, int val){
        if(i<l||i>r)return;
        if(l==r){
            tree[index].x = val;
            return;
        }
        int mid = (l+r)/2;
        update(2*index, l, mid, i, val);
        update(2*index+1, mid+1, r, i, val);
        tree[index] = merge(tree[2*index], tree[2*index+1]);
    }

    Node findkth(int index, int l, int r, int k){
        if(l==r){
            return Node(l);
        }
        int mid = (l+r)/2;
        //tree[2*index].x represents no of valid numbers in range l ... mid
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
