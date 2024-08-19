#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
#define endl '\n'
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;


//lazy always comes into play when theres a range update!!!!
//first always set then add***********

 
struct Node{
    int sum = 0;
    int maxr = 0;
    Node(int ss = 0, int mm = 0){
        sum = ss;
        maxr = mm;
    }
};

Node merge(Node x, Node y){
    Node ret;
    ret.sum = x.sum + y.sum;
    ret.maxr = max(x.maxr, y.maxr);
    return ret;
}
 
struct segTree{
    vector<Node> tree;
    vector<int> lazysum;
    vector<int> lazyset;
    vector<int> arr;
 
    void declare(int n, vector<int> a){
        tree.resize(4*n+400);
        lazysum.resize(4*n+400);
        lazyset.resize(4*n+400); 
        arr = a;
    }
 
    void build(int index, int l, int r){
        if(l == r){
            tree[index] = Node(arr[l], arr[l]); 
            return;
        }
 
        int mid = (l+r)/2;
 
        build(2*index, l, mid);
        build(2*index+1, mid+1, r);
 
        tree[index] = merge(tree[2*index], tree[2*index+1]);
    }
    
    void push(int index, int l, int r){
        if(lazyset[index] != 0){
            //set it at the corresponding tree[index]
            tree[index].sum = (r-l+1) * lazyset[index];
            tree[index].maxr = lazyset[index];
            //push downwards if not leaf node
            if(l != r){
                lazyset[2*index] = lazyset[index];
                lazyset[2*index+1] = lazyset[index];
                lazysum[2*index] = 0;
                lazysum[2*index+1] = 0;
            }
            //clear it off tree[index] once pushed
            lazyset[index] = 0;
        }
 
        if(lazysum[index] != 0){
            //set it at the corresponding tree[index]
            tree[index].sum += (r-l+1) * lazysum[index];
            tree[index].maxr += lazysum[index];
            //push downwards if not leaf node
            if(l != r){
                lazysum[2*index] += lazysum[index];
                lazysum[2*index+1] += lazysum[index];
            }
            //clear it off tree[index] once pushed
            lazysum[index] = 0;
        }
    }
 
    void update(int index, int l, int r, int st, int en, int val, int type){
        push(index, l, r);
        if(st > r || en < l){
            return;
        }
        if(st <= l && r <= en){
            if(type == 1){
                lazysum[index] += val; 
            } else {
                lazyset[index] = val;
                lazysum[index] = 0;
            }
            push(index, l, r);
            return;
        }
 
        int mid = (l+r)/2;
        update(2*index, l, mid, st, en, val, type);
        update(2*index+1, mid+1, r, st, en, val, type);
 
        tree[index] = merge(tree[2*index], tree[2*index+1]);
    }
 
    Node query(int index, int l, int r, int st, int en){
        push(index, l, r);
        if(st > r || en < l){
            return Node();
        }
        if(st <= l && r <= en){
            return tree[index];
        }
        int mid = (l+r)/2;
        return merge(query(2*index, l, mid, st, en), query(2*index+1, mid+1, r, st, en));
    }
};
 
void solve(){
   int n, q;
   cin >> n >> q;
   vector<int> arr(n);
   for(int i = 0; i < n; i++){
       cin >> arr[i];
   }
 
   segTree st;
   st.declare(n, arr);
   st.build(1, 0, n-1);
 
   while(q--){
       int ch;
       cin >> ch;
       if(ch == 1){
           int l, r, x;
           cin >> l >> r >> x;
           l--, r--;
           st.update(1, 0, n-1, l, r, x, 1);
       } else if(ch == 2){
           int l, r, x;
           cin >> l >> r >> x;
           l--, r--;
           st.update(1, 0, n-1, l, r, x, 2);
       } else {
           int l, r;
           cin >> l >> r;
           l--, r--;
           cout << st.query(1, 0, n-1, l, r).sum << endl;
       }
   }
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}







