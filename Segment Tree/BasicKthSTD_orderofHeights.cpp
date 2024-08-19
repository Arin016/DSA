#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

/*
There are N persons standing in the queue. They are numbered from 1 to N. Hi is the height 
of the person i. Pi is the number of persons who are taller than i and standing in front of i. 
Given these two arrays H and P, your task is to find the actual order of the queue. 
It is guaranteed that the height of each person will be unique.
*/

//we need to process from smallest of heights and find the smallest available position for it
// the leaf nodes of segtree represents the positions

// each node stores the number of elements from the array present in this range l....r
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

struct segTree {
    vector<Node> tree;
    vector<int> a;

    void init(int n, vector<int> arr) {
        a.resize(n + 100);
        tree.resize(4 * n + 400);
        a = arr;
    }

    void build(int index, int l, int r) {
        if (l == r) {
            tree[index] = Node(1);  
            return;
        }
        int mid = (l + r) / 2;
        build(2 * index, l, mid);
        build(2 * index + 1, mid + 1, r);
        tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
    }

    //yeh merko ith smallest position update karke dega
    void updateKthsmallest(int index, int l, int r, int i, int val) {
        if (l == r) {
            tree[index] = Node(val);  
            return;
        }
        int mid = (l + r) / 2;
        if (i <= tree[2 * index].x) updateKthsmallest(2 * index, l, mid, i, val);
        else updateKthsmallest(2 * index + 1, mid + 1, r, i - tree[2 * index].x, val);
        tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
    }

    //yeh merko ith position update karke dega
    void updatepos(int index, int l, int r, int i, int val){
        if(i<l||i>r)return;
        if(l==r){
            tree[index].x = val;
            return;
        }
        int mid = (l+r)/2;
        updatepos(2*index, l, mid, i, val);
        updatepos(2*index+1, mid+1, r, i, val);
        tree[index] = merge(tree[2*index], tree[2*index+1]);
    }
    //kth segtree query
    int findkth(int index, int l, int r, int k) {
        if (l == r) {
            return l;  
        }
        int mid = (l + r) / 2;
        if (k <= tree[2 * index].x) return findkth(2 * index, l, mid, k);
        else return findkth(2 * index + 1, mid + 1, r, k - tree[2 * index].x);
    }
};

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    //mp[x] = person number
    //x = his height
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mp[x] = i;
    }
    vector<int> p(n);
    for(int i=0;i<n;i++)cin>>p[i];
    segTree st;
    st.init(n, vector<int>(n, 0));
    st.build(1, 0, n-1);
    vector<int> ans(n);
    for(auto x:mp){
        int height = x.first;
        int person = x.second;
        //agar iss current person ke samne p[person] number of log khade rehne chaiye toh
        //yeh current position ko kis position par hona chaiye?
        // (p[person]+1)th smallest available postion
        int k = p[person]+1;
        int pos = st.findkth(1, 0, n-1, k); //found out kth smallest available position
        ans[pos] = person+1; //uss position par khada kar diya
        // st.updateKthsmallest(1, 0, n-1, k, 0);
        st.updatepos(1, 0, n-1, pos, 0); //pos wale position ko update kar diya
        //either kth smallest position ko update kar ya phir kth smallest position ko pata kar aur
        //phir usko update kar
    }
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
    
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
