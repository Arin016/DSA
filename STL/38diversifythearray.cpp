#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

void solve(){
    int n, k;
    cin>>n>>k;
    map<int, int> mp;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mp[x]++;
    }
    int ans = (n*(n-1))/2;
    priority_queue<int> pq;
    for(auto x:mp){
        if(x.second>1){
            ans-=(x.second*(x.second-1))/2;
            pq.push(x.second);
        }
    }

    while(k--){
        if(pq.empty())break;
        int val = pq.top();
        pq.pop();
        ans+=val-1;
        val--;
        if(val>1)pq.push(val);
    }
    
    cout<<ans<<endl;
    
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
    return 0;
}
