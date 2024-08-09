#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int fun(int n, int p){
    int ans = 0;
    int power = p;
    while(n / power > 0){
        ans += (n / power);
        if (power > n / p) break; 
        power *= p;
    }
    return ans;
}

vector<pair<int, int>> factorise(int x){
    vector<pair<int, int>> ans;
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0){
            int cnt = 0;
            while(x % i == 0){
                x = x / i;
                cnt++;
            }
            ans.push_back({i, cnt});
        }
    }

    if(x != 1){
        ans.push_back({x, 1});
    }

    return ans;
}

void solve(){
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> fact = factorise(x);
    int ans = LLONG_MAX;
    for(auto v : fact){
        ans = min(ans, fun(n, v.first) / v.second);
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}