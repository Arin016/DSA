#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    //depth = #of open brackets - #of closed brackets
    //open brackets put +1 closed ones put -1
    //criteria:
    //depth at the end = 0
    //what happens to depth in b/w
    //depth shouldnt go -ve -># of closed> # of open
    //depth at end = 0 and depth>=0 at all points
    string s;
    cin>>s;

    int depth = 0;
    bool isbalanced = true;
    for(auto x:s){
        if(x=='(')depth++;
        else depth--;
        if(depth<0){
            isbalanced = false;
            break;
        }
    }
    if(isbalanced and depth==0)cout<<"YES"<<endl; //checking through both the criterions
    else cout<<"NO"<<endl;


    //({[]}) check if this is balanced??
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
