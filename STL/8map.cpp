#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
#define endl "\n"

void solve(){
    int q;
    cin>>q;
    map<string, int> mp;
    while(q--){
        string s;
        cin>>s;
        if(s=="add"){
            int y;
            string x;
            cin>>x>>y;
            mp[x] = y;
        }
        else if(s=="erase"){
            string x;
            cin>>x;
            if(mp.count(x))mp.erase(mp.find(x));
        }
        else{
            string x;
            cin>>x;
            if(mp.count(x)){
                cout<<mp.find(x)->second<<endl;
            }
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
