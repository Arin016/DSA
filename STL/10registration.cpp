#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    map<string, int> mp;
    int q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        if(mp.count(s)){
            mp[s]++;
            cout<<mp.find(s)->first<<mp.find(s)->second<<endl;
        }
        else {
            cout<<"OK"<<endl;
            mp[s]=0;
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
