#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
string t = "0100";

int rec(int level, int match){
    //pruning
    if(match==4)return 0;
    //base case
    if(level==n)return 1;
    //cache check
    //compute
    int ans = 0;
    if(match==0){
        //put 1
        ans+=rec(level+1, 0);
        //put 0
        ans+=rec(level+1, 1);
    }
    else if(match==1){
        //put 1
        ans+=rec(level+1, 2);
        //put 0
        ans+=rec(level+1, 1);
    }
    else if(match==2){
        //put 1
        ans+=rec(level+1, 0);
        //put 0
        ans+=rec(level+1, 3);
    }
    else if(match==3){
        //put 1
        ans+=rec(level+1, 2);
        //put 0
        ans+=rec(level+1, 4);
    }
    //save and return
    return ans;
}
void solve(){
    cin>>n;
    cout<<rec(0, 0)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
