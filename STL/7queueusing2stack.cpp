#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    int q;
    cin>>q;
    stack<int> st1, st2;
    while(q--){
        string s;
        cin>>s;
        if(s=="push"){
            int x;
            cin>>x;
            st1.push(x);
        }
        else if(s=="pop"){
            if(st2.empty()){
                while(!st1.empty()){
                    st2.push(st1.top());
                    st1.pop();
                }
            }
            cout<<st2.top()<<endl;
            st2.pop();
        }
        else{
            if(st2.empty()){
                while(!st1.empty()){
                    st2.push(st1.top());
                    st1.pop();
                }
            }
            cout<<st2.top()<<endl;
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
