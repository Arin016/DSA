#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const ll mod = 1e9 + 9;

ll binpow(ll a,ll b,ll m){
    if(a%m==0 and b!=0) return 0;
    ll ans=1;
    ll base=(a)%mod;

    while(b!=0){
        if(b%2){
            ans=(ans*base)%mod;
        }
        base=(base*base)%mod;
        b=b>>1;
    }
    return ans;
}

//formula based ques
//write f1 f2 f3 and then look for relations and create a generic formula and compute them separately

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 

    int _t;
    cin >> _t;

    while (_t--) {
        ll a, b, n;
        cin >> a >> b >> n;

        if (a == 1) {
            ll ans = (b % mod) * (n % mod) % mod;
            ans = (ans + 1) % mod;
            cout << ans << "\n";
        } else {
            ll ans1 = binpow(a, n, mod);
            ll ans2 = (ans1 - 1 + mod) % mod;
            ll ans3 = binpow(a - 1, mod - 2, mod);
            ll ans4 = ((b % mod) * (ans2 % mod)) % mod;
            ans4 = (ans4 * ans3) % mod;
            ll ans = (ans1 + ans4) % mod;
            cout << ans << "\n";
        }   
    }

    return 0;
}