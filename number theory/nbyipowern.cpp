#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define endl '\n'

int binpow(int a,int b){
    int ans = 1; 
    a%=mod;
    while(b){
        if(b%2==1){
            ans= ans*a % mod;
        }
        a = a*a % mod;
        b/=2;
    }
    return ans%mod;
}


void solve(){
    int n,m;
    cin>>n>>m;
    int i = 1;
    int ans = 0;
    while(i<=n){
        int x = (n/(n/i));
        ans+= (binpow((n/i),m)*(((x-i+1)%mod)+mod)%mod)%mod;
        ans%=mod;
        i=(x+1);
    }
	cout<<ans<<endl;

 }

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // int t;cin>>t;
    // while(t--) 
    solve();
}