#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
//prefer writing the automata code instead as its more handy!
//whenevr some sort of small match and string based --> AUTOMATA!
//(level ,match)
int n;
string t = "0100";

int rec(int level, int last3){
    //pruning
    //base case
    if(level==n)return 1;
    //cache check
    //compute
    int ans = 0;
    if(level>=3 and last3==2){ //010
        //dont count when placing 1 now
        ans=rec(level+1, ((last3<<1)|1)&(7));
    }
    else{
        ans+=rec(level+1, ((last3<<1)|1)&(7));
        ans+=rec(level+1, ((last3<<1)|0)&(7));
    }
    //save and return
    return ans;
}
void solve(){
    cin>>n;
    cout<<rec(0, 0)<<endl;
    //wanna push a 0 bit at the end of x --> x<<1!
    //wanna prune the last bit of x --> x>>1!
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
