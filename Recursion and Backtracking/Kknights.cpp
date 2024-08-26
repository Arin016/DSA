#include<bits/stdc++.h>
using namespace std;
#define int long long

int mod = 1e9+7;
int n, k;
vector<pair<int, int>> knights;
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2}; // Knight's possible moves
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool check(int row, int col) {
    for(auto &knight : knights) {
        int x = knight.first;
        int y = knight.second;
        for(int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx == row && ny == col) return false;
        }
    }
    return true;
}

int rec(int row, int col, int k) {
    if(k == 0) return 1;
    if(row == n) return 0; // Valid configuration found
    if(col == n) return rec(row + 1, 0, k); // Move to the next row
    
    int ans = 0;
    ans += rec(row, col + 1, k); // Skip this cell
    ans %= mod; // Apply modulo
    
    if(check(row, col)) { // Place knight if safe
        knights.push_back({row, col});
        ans += rec(row, col + 1, k - 1); // Place a knight
        ans %= mod; // Apply modulo
        knights.pop_back();
    }
    
    return ans;
}

void solve() {
    cin >> n >> k;
    knights.clear();
    cout << rec(0, 0, k) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
