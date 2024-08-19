#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define int long long
const int mod = 1e9+7;

lli binpowi(lli a, lli b, lli mod){
    lli res=1;
    while(b>0){
        if(b&1){
        res = (res%mod*a%mod)%mod;
        }
        a = (a%mod*a%mod)%mod;
        b>>=1;
    }
    return ((res%mod)+mod)%mod;
}

lli inverse(lli a, lli mod){
    return ((binpowi(a, mod-2, mod)%mod)+mod)%mod;
}

lli fact[202020];
void factorial(lli mod){
    fact[0] = 1;
    for(int i=1;i<202020;i++){
        fact[i] = (i%mod*fact[i-1]%mod)%mod;
    }
}

lli ncr(lli n, lli r, lli mod){
    if(r<0||r>n)return 0;
    lli nume = fact[n];
    lli deno = (fact[n-r]%mod*fact[r]%mod)%mod;
    return (nume%mod*inverse(deno, mod))%mod;
}

//a^x%p = (a%p)^(x%(p-1))%p if p is prime 
using state = pair<int, int>;
void solve(){
    //factorial(mod);
    
    
    
}

signed main(){
    int _t=1;
    //cin>>_t;
    while(_t--){
        solve();
    }
}