#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    string s;
    cin>>s;
    int n = s.length();
    int ans = 0;
    int i=0;
    while(s[i]==')'){
        i++;
    }
    i--;
    int j=n-1;
    while(s[j]=='('){
        j--;
    }
    j++;
    ans+=(i-0+1)+(n-1-j+1);
    // cout<<i<<endl;
    // cout<<"l"<<" "<<j<<endl;
    int depth = 0;
    for(int k=i+1;k<j;k++){
        if(s[k]=='('){
            depth++;
        }
        else depth--;
        if(depth<0)ans++, depth++;
    }
    cout<<ans+depth<<endl;
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
