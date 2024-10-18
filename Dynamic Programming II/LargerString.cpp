#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
string l, r;

int rec(int level, int tlo, int thi){
    //pruning
    //base case
    if(level==n){
        return 1;
    }
    //cache check
    //compute
    int ans = 0;
    char lo = 'A';
    if(tlo==1){
        lo = max(l[level], l[n-1-level]);
    }
    char hi = 'Z';
    if(thi==1){
        hi = r[level];
    }
    for(char i=lo;i<=hi;i++){
        int newtlo = tlo, newthi = thi;
        if(i!=lo)newtlo = 0;
        if(i!=hi)newthi = 0;
        ans+=rec(level+1, newtlo, newthi);
    }
    //save and return
    return ans;
}

void solve(){
    cin>>l;
    r = "";
    while(r.length()<l.length()){
        r+='Z';
    }
    n = l.length();
    cout<<rec(0, 1, 1)<<endl;
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
