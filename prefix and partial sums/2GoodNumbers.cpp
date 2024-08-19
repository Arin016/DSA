#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, k, q;
int a[1000100];
void solve(){
    cin>>n>>k>>q;
    // Partial sums
    for(int i = 0; i < n; i++){
        int l, r;
        cin>>l>>r;
        l--, r--;
        a[l]++;
        if(r + 1 < 1000100) a[r + 1]--;
    }

    // Calculate prefix sums to get how many people like a particular number
    for(int i = 1; i < 1000100; i++){
        a[i] += a[i-1];
    }

    // Technique for counting numbers >= k in a range
    for(int i = 0; i < 1000100; i++){
        if(a[i] >= k) a[i] = 1;
        else a[i] = 0;
    }

    // Prefix sum again to answer range queries efficiently
    for(int i = 1; i < 1000100; i++){
        a[i] += a[i-1];
    }

    while(q--){
        int l, r;
        cin>>l>>r;
        l--, r--;
        cout<<((l - 1 >= 0) ? a[r] - a[l-1] : a[r])<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}
