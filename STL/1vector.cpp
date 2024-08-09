#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;




void solve(){
    int q;
    cin>>q;
    vector<int> v;
    while(q--){
        string s;
        cin>>s;
        if(s=="add"){
            int x;
            cin>>x;
            v.push_back(x);
        }
        else if(s=="print"){
            int x;
            cin>>x;
            if((int)(v.size())-1>=x){ //v.size() is an iterator use typecasting
                cout<<v[x]<<endl;
            }
            else cout<<0<<endl;
        }
        else if(s=="remove"){
            if(!v.empty())v.pop_back();
        }
        else {
            v.clear();
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
