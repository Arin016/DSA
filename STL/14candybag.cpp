#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    int n, k;
    cin>>n>>k;
    int a[n];
    priority_queue<int> pq;
    for(int i=0;i<n;i++)cin>>a[i], pq.push(a[i]);
    int ans = 0;
    while(k--){
        int temp = pq.top();
        pq.pop();
        ans+=temp;
        pq.push(temp/2);
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
