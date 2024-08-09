#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    int q;
    cin>>q;
    multimap<string, int> mp;
    while(q--){
        string s;
        cin>>s;
        if(s=="add"){
            string x;
            int y;
            cin>>x>>y;
            mp.insert({x, y}); //weird way to insert
        }
        else if(s=="erase"){
            string x;
            cin>>x;
            if(mp.count(x)){
                mp.erase(mp.find(x)); //erases the first occurance of x
            }
        }
        else if(s=="eraseall"){
            string x;
            cin>>x;
            while(mp.count(x)){
                mp.erase(mp.find(x));
            }
            //mp.erase(x);
        }
        else{
            string x;
            cin>>x;
            if(mp.count(x)){
                cout<<mp.find(x)->second<<endl;
            }
            else{
                cout<<0<<endl;
            }
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
