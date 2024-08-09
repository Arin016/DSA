#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    int q;
    cin>>q;
    priority_queue<int> pq;
    while(q--){
        string s;
        cin>>s;
        if(s=="add"){
            int x;
            cin>>x;
            pq.push(x);
        }
        else if(s=="remove"){
            if(!pq.empty())pq.pop();
        }
        else{
            if(!pq.empty())cout<<pq.top()<<endl;
            else cout<<0<<endl;
        }
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
