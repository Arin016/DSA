    #include<bits/stdc++.h>
    using namespace std;
    #define int long long
    int mod = 1e9+7;

    int n, q;
    int a[1000100];

    int t[4000400];
    void build(int index, int l, int r){
        if(l==r){
            t[index] = a[l];
            return;
        }
        int mid = (l+r)/2;
        build(2*index, l, mid);
        build(2*index+1, mid+1, r);
        t[index] = t[2*index]^t[2*index+1];
    }

    void update(int index, int l, int r, int ind, int val){
        if(ind<l||ind>r)return;
        if(l==r){
            t[index] = val;
            a[index] = val;
            return;
        }
        int mid = (l+r)/2;
        update(2*index, l, mid, ind, val);
        update(2*index+1, mid+1, r, ind, val);
        t[index] = t[2*index]+t[2*index+1];
    }

    int query(int index, int l, int r, int lq, int rq){
        if(rq<l||lq>r)return 0;
        if(l>=lq and rq>=r){
            return t[index];
        }
        int mid = (l+r)/2;
        return query(2*index, l, mid, lq, rq)^query(2*index+1, mid+1, r, lq, rq);
    }

    void solve(){
        cin>>n>>q;
        for(int i=0;i<n;i++)cin>>a[i];
        build(1, 0, n-1);
        while(q--){
            int a, b;
            cin>>a>>b;
            a--, b--;
            cout<<query(1, 0, n-1, a, b)<<endl;
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
