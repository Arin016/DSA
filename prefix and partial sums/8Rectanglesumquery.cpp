// Construct the 2D prefix sum array in row major order just like DP based idea
//to figure out ans for i, j you use ans of i-1, j and i, j-1 and i-1, j-1


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;

void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            a[i][j] %= mod;  
        }
    }

    // Construct the 2D prefix sum array
    vector<vector<int>> p(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            p[i][j] = a[i][j] % mod;
            if(i > 0) p[i][j] = (p[i][j] % mod + p[i-1][j] % mod) % mod;
            if(j > 0) p[i][j] = (p[i][j] % mod + p[i][j-1] % mod) % mod;
            if(i > 0 && j > 0) p[i][j] = (p[i][j] % mod - p[i-1][j-1] % mod + mod) % mod;
        }
    }

    // Answer the queries
    while(q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        int ans = p[c][d] % mod;
        if(b > 0) ans = (ans % mod - p[c][b-1] % mod + mod) % mod;
        if(a > 0) ans = (ans % mod - p[a-1][d] % mod + mod) % mod;
        if(a > 0 && b > 0) ans = (ans % mod + p[a-1][b-1] % mod) % mod;
        cout << (ans+mod)%mod << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
