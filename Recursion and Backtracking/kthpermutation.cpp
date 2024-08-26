#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9+7;

int n, k;
map<int, int> f;
vector<int> sol;
vector<int> fact; 

// Function to precompute factorials up to n
void precompute_factorials(int n) {
    fact.resize(n+1);
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = (fact[i-1] * i) % mod;
    }
}

void rec(int level) {
    if(level == n) {
        for(auto x: sol) {
            cout << x << " ";
        }
        cout << endl;
        return;
    }
    for(auto &x: f) {
        if(x.second > 0) {
            sol.push_back(x.first);
            f[x.first]--;
            rec(level + 1);
            f[x.first]++;
            sol.pop_back();
        }
    }
}

void kth(int level, int k) {
    if(level == n) {
        return;
    }
    int val = 0;
    for(auto &x: f) {
        if(x.second > 0) {
            if(k <= val + fact[n-level-1]) {
                cout << x.first << " ";
                f[x.first]--;
                kth(level + 1, k - val);
            }
            val += fact[n-level-1];
        }
    }
}

void solve() {
    cin >> n >> k;
    f.clear();
    sol.clear();
    precompute_factorials(n); 
    if(n <= 13) {
        for(int i = 1; i <= n; i++) {
            f[i]++;
        }
        kth(0, k);
    } else {
        for(int i = 1; i <= n-13; i++) {
            cout << i << " ";
        }
        for(int i = n-12; i <= n; i++) {
            f[i]++;
        }
        kth(n-13, k);
    }
    cout << endl;
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
}
