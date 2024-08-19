#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

struct Node{
    pair<int, int> p;
};

struct segTree{
    vector<Node> tree;
    vector<int> arr;

    void declaring(int n, vector<int> a){
        tree.resize(4*n + 400);
        arr = a;
    }
    //each node stores (mini in range, cnt of that mini)
    pair<int, int> merge(pair<int, int> x, pair<int, int> y){
        if(x.first==y.first)return {x.first, x.second+y.second};
        else if(x.first>y.first)return y;
        else return x;
    }

    void build(int index, int l, int r){
        if(l==r){
            tree[index].p.first = arr[l];
            tree[index].p.second = 1;
            return;
        }

        int mid = (l+r)/2;
        
        build(2*index,l,mid);
        build(2*index+1,mid+1,r);
        tree[index].p = merge(tree[2*index].p, tree[2*index+1].p);
    }

    void update(int index, int l, int r, int pos, int val){
        if(pos<l || pos>r){
            return;
        }

        if(l==r){
            tree[index].p.first = arr[l];
            tree[index].p.second = 1;
            return;
        }

        int mid = (l+r)/2;
        
        update(2*index,l,mid,pos,val);
        update(2*index+1,mid+1,r,pos,val);
        tree[index].p = merge(tree[2*index].p, tree[2*index+1].p); 
    }

    pair<int, int> query(int index, int l, int r, int st, int en){
        if(en<l || st>r){
            return {LLONG_MAX, 0};
        }

        if(st<=l && r<=en){
            return tree[index].p;
        }

        int mid = (l+r)/2;

        return merge(query(2*index,l,mid,st,en),query(2*index+1,mid+1,r,st,en));
    }
};


void solve(){
   int n,q;
   cin>>n>>q;
   vector<int>a(n);
   for(int i=0;i<n;i++){
        cin>>a[i];
   }

   segTree st;
   st.declaring(n,a);
   st.build(1,0,n-1);
    while(q--){
        int x;
        cin>>x;
        if(x==1){
            //update
            int pos,val;
            cin>>pos>>val;
            pos--;
            st.update(1,0,n-1,pos,val);
        }else{
            //query
            int s,e;
            cin>>s>>e;
            s--,e--;
            auto ans = st.query(1,0,n-1,s,e);
            cout<<ans.first<<" "<<ans.second<<endl;
        }
    }
    
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}