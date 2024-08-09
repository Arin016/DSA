#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


bool comp(pair<string, int> &a, pair<string, int> &b){
    //return true for such a condition that "a" must come before "b"
    return a.second<b.second;
}

void solve(){
    int n;
    cin>>n;
    vector<pair<string, int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin(), a.end(), comp);
    for(auto x:a){
        cout<<x.first<<" "<<x.second<<endl;
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
