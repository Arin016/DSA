#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
vector<int> a;
int inversioncnt; //number of pairs (i, j) where i<j and a[i]>a[j]
//lemma: every non equal element swap in the array changes the inversioncnt by odd number, 
//so the parity of inversion flips

vector<int> merge(vector<int> a, vector<int> b) {
    vector<int> c(a.size() + b.size());
    int i = 0, j = 0, k = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            c[k++] = a[i++];
        } else { //b[j]<a[i]
            inversioncnt+=(a.size()-i);
            c[k++] = b[j++];
        }
    }
    while (i < a.size()) {
        c[k++] = a[i++];
    }
    while (j < b.size()) {
        c[k++] = b[j++];
    }
    return c;
}

vector<int> mergesort(int l, int r){
    if(l == r){
        return {a[l]};
    }
    int mid = (l + r) / 2;
    vector<int> left = mergesort(l, mid);
    vector<int> right = mergesort(mid + 1, r);
    return merge(left, right);
}

void solve(){
    cin >> n;
    a.resize(n);
    inversioncnt = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> ans = mergesort(0, n - 1);
    // for(auto x : ans){
    //     cout << x << " ";
    // } 
    // cout << endl;
    cout<<(inversioncnt&1)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
