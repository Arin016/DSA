#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, q, max_c;
vector<vector<vector<int>>> stars;
vector<vector<vector<int>>> dp; // DP table to cache results of rec(x, y, bb)

int rec(int x, int y, int bb){
    //number of stars with brightness == bb in (1, 1) .... (x, y)
    //pruning
    if(x < 0 || y < 0) return 0;  // Base case: if out of bounds, return 0
    if(x > 100 || y > 100) return 0;

    // if already computed, return the cached value
    if(dp[x][y][bb] != -1) return dp[x][y][bb];
    
    //compute
    int ans = 0;
    ans += stars[x][y][bb];
    ans += rec(x - 1, y, bb);     // Moving left in x
    ans += rec(x, y - 1, bb);     // Moving up in y
    ans -= rec(x - 1, y - 1, bb); // Removing over-counted corner
    
    // cache the result before returning
    return dp[x][y][bb] = ans;
}

void solve(){
    cin >> n >> q >> max_c;
    stars.assign(100+1, vector<vector<int>>(100+1, vector<int>(12, 0))); 
    dp.assign(101, vector<vector<int>>(101, vector<int>(12, -1))); // Initialize dp with -1

    for(int i = 0; i < n; i++){
        int x, y, cc;
        cin >> x >> y >> cc;
        stars[x][y][cc]++;
    }
    
    while(q--){
        int m, a, b, c, d;
        cin >> m >> a >> b >> c >> d;
        int x1 = a, y1 = b, x2 = c, y2 = d;
        int ans = 0;
        
        for(int bb = 0; bb <= 10; bb++){
            int brightness_contrib = (rec(x2, y2, bb) - rec(x1-1, y2, bb) - rec(x2, y1-1, bb) + rec(x1-1, y1-1, bb));
            ans += brightness_contrib * ((bb + m) % (max_c + 1));
        }
        
        cout << ans << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
