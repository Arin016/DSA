#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;



struct bag {
    vector<int> pref;
    
    bag() {
        pref.clear();
    }

    int binpowi(int a, int b, int mod){
        a %= mod;
        int res = 1;
        while(b > 0){
            if(b & 1){ 
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    int inverse(int a, int mod){
        return binpowi(a, mod-2, mod);
    }

    void add(int x) {
        if(x == 0) {
            pref.clear();
        } else {
            if(pref.empty()) {
                pref.push_back(x % mod);
            } else {
                pref.push_back((x * pref.back()) % mod);
            }
        }
    }

    int getProduct(int k) {
        int n = pref.size();
        if(n < k) {
            return 0;
        } else if(n == k) {
            return pref.back() % mod;
        } else {
            return (pref.back() * inverse(pref[n-k-1], mod)) % mod;
        }
    }
};

void solve() {
    int q;
    cin >> q;
    bag bg;
    while(q--) {
        string s;
        cin >> s;
        if(s == "add") {
            int x;
            cin >> x;
            bg.add(x);
        } else {
            int k;
            cin >> k;
            cout << bg.getProduct(k) << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--) {
        solve();
    }
}