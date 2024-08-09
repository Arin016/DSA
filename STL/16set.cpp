#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    int q;
    cin>>q;
    set<int> st;
    while(q--){
        string s;
        cin>>s;
        if(s=="add"){
            int x;
            cin>>x;
            st.insert(x);
        }
        else if(s=="erase"){
            int x;
            cin>>x;
            if(st.count(x))st.erase(st.find(x));
        }
        else if(s=="find"){
            int x;
            cin>>x;
            if(st.count(x))cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else if(s=="print"){
            for(auto it=st.begin();it!=st.end();it++){
                cout<<*it<<" ";
            }
            cout<<endl;
        }
        else{
            st.clear();
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
