#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


vector<int> prevsmaller(int* a, int n){
    vector<int> ans(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() and a[st.top()]>=a[i])st.pop();
        if(!st.empty())ans[i] = st.top()+1;
        else ans[i] = -1+1;
        st.push(i);
    }
    return ans;
}

vector<int> nextsmaller(int* a, int n){
    vector<int> ans(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() and a[st.top()]>=a[i])st.pop();
        if(!st.empty())ans[i] = st.top()-1;
        else ans[i] = n-1;
        st.push(i);
    }
    return ans;
} 

void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int> prevsm = prevsmaller(a, n);
    vector<int> nextsm = nextsmaller(a, n);
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=a[i]*(i-prevsm[i]+1)*(nextsm[i]-i+1);
    }
    cout<<ans<<endl;
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
