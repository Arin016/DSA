#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    //here we are asked for the nearest piche wala thing when we are currently processing at some
    //index, this brings in the need for usage of a stack as it is a LIFO data Structure

    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() and a[st.top()]>=a[i]){
            st.pop();
        }
        if(st.empty())cout<<0<<" ";
        else cout<<st.top()+1<<" ";
        st.push(i);
    }
    cout<<endl;
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
