#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    //optimisation in algorithmic design:
    //either theres an observation or share information/precomputation
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    multiset<int> mt;
    for(int i=0;i<n;i++){
        //insert
        mt.insert(a[i]);
        //delete
        //(i-k)th element should be removed from our window 
        if(i-k>=0)mt.erase(mt.find(a[i-k])); //thinking about these to get formulaes think about index "zero"
        //print for the window
        if(mt.size()==k){
            cout<<*mt.begin()<<endl;
        }
    }

    //insert remove getdistinct sum -->map
    //instead of set+multiset use MAP

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
