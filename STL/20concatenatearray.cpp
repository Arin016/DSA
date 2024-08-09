#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    int n;
    cin>>n;
    set<int> st;
    //You are given an array A of N integers. 
    //Find the length of the largest increasing subsequence if the array A is concatenated to itself N times
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        st.insert(x);
    }
    cout<<st.size()<<endl;
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
