#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod = 1e9+7;
//look at this cal function carefully!!!!!!!!!! and go through this question again
int call(int n) {
    int x = n, y = n + 1;
    if(x % 2 == 0) x /= 2;
    else y /= 2;
    x %= mod; y %= mod;
    int ans = x * y % mod;
    if(ans < 0) ans += mod;
    return ans;
}

int get(int n, int m){
    int len = n/m;
    int sum1 = (len%mod*call(m-1)%mod)%mod;
    int len2 = n%m;
    int sum2 = call(len2)%mod;
    int sum  = (sum1%mod+sum2%mod)%mod;
    return sum%mod;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r, m;
        cin >> l >> r >> m;
        int ans = get(r,m)-get(l-1,m);
        ans = ans%mod;
        if(ans<0){
            ans+=mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}