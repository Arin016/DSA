#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll M = 1e9+7;
const ll N = 1e6+1;
ll arr[N], arr2[N];
ll pf[N], pf2[N];

ll mul(ll a, ll b)
{
    ll ans = (1LL*a*b) % M;
    if(ans<0){
        ans+=M;
    }
    return ans;
}

//an element in the range l to r could be Ai+(i-L)*Di
//split and kill constat terms and linear seperately
void solve()
{
    ll n, q;
    cin >> n >> q;
    ll a, d, l, r;
    while(q--){
        cin >> a >> d >> l >> r;
        arr[l] += (a - mul(l, d));
        arr[r+1] -= (a - mul(l, d));
        arr2[l] += d;
        arr2[r+1] -= d;
    }
    for(ll i=1;i<=n;i++){
        pf[i] = pf[i-1] + arr[i];
        pf2[i] = pf2[i-1] + arr2[i];
    }
    for(ll i=1;i<=n;i++){
        cout << (((pf[i] + mul(pf2[i], i)) % M) + M) % M << " ";
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //int t;cin >> t;while(t--)
    solve();
}
