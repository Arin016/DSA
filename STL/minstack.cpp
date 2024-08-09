#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;

void solve(){
    stack<int> st;         // Main stack to store elements
    stack<int> minst;      // Stack to keep track of minimum values

    int q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        
        if(s == "top"){
            if(st.empty()){
                cout << "Empty\n";
            } else {
                cout << st.top() << "\n";
            }
        }
        else if(s == "pop"){
            if(st.empty()){
                cout << "Empty\n";
            } else {
                st.pop();
                minst.pop();
            }
        }
        else if(s == "push"){
            int x;
            cin >> x;
            st.push(x);
            if(!minst.empty()){
                minst.push(min(minst.top(), x));
            } else {
                minst.push(x);  // If minst is empty, push the first element as the minimum
            }
        }
        else if(s == "min"){
            if(minst.empty()){
                cout << "Empty\n";
            } else {
                cout << minst.top() << "\n";
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
