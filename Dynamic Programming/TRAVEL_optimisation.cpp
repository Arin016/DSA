#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m, k;
vector<int> b, a;
vector<vector<int>> dp;

struct monotoneDeque {
    deque<int> dq; 
    void insert(int x) {
        while (!dq.empty() && dq.back() > x) {
            dq.pop_back();
        }
        dq.push_back(x);
    }

    void remove(int x) {
        if (!dq.empty() && dq.front() == x) {
            dq.pop_front();
        }
    }

    int getmin() {
        if (!dq.empty()) return dq.front();
        return 1e18; 
    }

    void clear() {
        dq.clear();
    }
};


// int rec(int level, int num_flight, monotonic_deque &dq){
//     if(level >= n){
//         return INF; 
//     }
//     if(level == n-1){
//         return 0;
//     }

//     if(dp[level][num_flight] != -1){
//         return dp[level][num_flight];
//     }

//     int ans = b[level] + rec(level+1, num_flight, dq);
    
//     if(num_flight > 0){
//         int next_cost = rec(level+1, num_flight-1, dq) + a[level+1];
//         dq.insert(next_cost);
//         if(level + k + 1 < n){
//             int erase_cost = rec(level+k+1, num_flight-1, dq) + a[level+k+1];
//             dq.erase(erase_cost);
//         }
//         ans = min(ans, a[level] + dq.get_min());
//     }

//     return dp[level][num_flight] = ans;
// }

void solve() {
    cin >> n >> m >> k;
    a.resize(n);
    b.resize(n);
    dp.assign(n, vector<int>(m + 1, -1)); // Resize and initialize dp with -1
    
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Bus cost
    }
    
    for (int i = 0; i < n; i++) {
        cin >> b[i]; // Flight cost
    }
    monotoneDeque md;
    for(int mm=0;mm<=m;mm++){
        for(int level=n-1;level>=0;level--){
            // base case
            if (level == n - 1) {
                dp[level][mm] =  0;
                continue;
            }  
            // compute
            int ans = 1e18;
            
            // Option 1: Take bus to the next city
            ans = min(ans, a[level] + dp[level + 1][mm]);
            
            // Option 2: Take a flight to any city within k range
            // First insert the result of the next step (flight) into the deque
            md.insert(b[level + 1] + dp[level + 1][mm - 1]);
            
            // Maintain the sliding window: remove results outside the range
            if (level + k + 1 < n) {
                md.remove(b[level + k + 1] + dp[level + k + 1][mm - 1]);
            }
            
            // Get the minimum flight cost within the sliding window and update answer
            ans = min(ans, b[level] + md.getmin());
            
            // store in dp and return
            dp[level][mm] = ans;
        }
    }
    cout<<dp[0][m]<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
