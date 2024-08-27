#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


int n;
int a[1000100];


void solve(){
    cin>>n;
    set<int> st;
    for(int i=0;i<n;i++)cin>>a[i], st.insert(a[i]);
    int k = st.size();
    //subarray is a big hint for the problem to be two pointers
    int head = -1, tail = 0;
    int ans = n;
    //data structure
    map<int, int> mp;
    int dcnt = 0;
    while(tail<n){
        while(head+1<n and (dcnt<k)){
            head++;
            //update DS
            if(mp[a[head]]==0)dcnt++;
            mp[a[head]]++;
        }
        if(dcnt==k)ans = min(ans, head-tail+1);
        if(head>=tail){
            //update DS
            mp[a[tail]]--;
            if(mp[a[tail]]==0)dcnt--;
            tail++;
        }
        else{
            tail++;
            head = tail-1;
        }
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
