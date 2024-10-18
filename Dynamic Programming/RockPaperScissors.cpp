#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
int n, k;
string s;
vector<vector<vector<int>>> dp;  // Caching table

// R -> A, 0
// P -> B, 1
// S -> C, 2

int rec(int level, int k, int prev) {
    // Pruning
    if (k < 0) return -1e18;  // Use proper negative infinity for int
    
    // Base case
    if (level == n) return 0;

    // Cache check
    if (dp[level][k][prev] != -1) return dp[level][k][prev];

    // Compute
    int ans = -1e18;
    int temp = s[level] - 'A';
    for(int cur=0;cur<3;cur++){
        if(temp==cur){ //draw cases!
            if(cur==prev) ans = max(ans, rec(level+1, k, cur));
            else ans = max(ans, rec(level+1, k-1, cur));
        }
        else if(temp!=cur){
            if(cur==0 and temp==2){ //win
                if(cur==prev) ans = max(ans, 1+rec(level+1, k, cur));
                else ans = max(ans, 1+rec(level+1, k-1, cur));
            }
            else if(cur==1 and temp==0){ //win
                if(cur==prev) ans = max(ans, 1+rec(level+1, k, cur));
                else ans = max(ans, 1+rec(level+1, k-1, cur));
            }
            else if(cur==2 and temp==1){ //win
                if(cur==prev) ans = max(ans, 1+rec(level+1, k, cur));
                else ans = max(ans, 1+rec(level+1, k-1, cur));
            }
            else{ //loose
                if(cur==prev) ans = max(ans, rec(level+1, k, cur));
                else ans = max(ans, rec(level+1, k-1, cur));
            }
        }
    }
    // Save and return
    return dp[level][k][prev] = ans;
}


void solve() {
    cin >> n >> k >> s;

    // Transforming input characters to A, B, C
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') s[i] = 'A';
        else if (s[i] == 'P') s[i] = 'B';
        else if (s[i] == 'S') s[i] = 'C';
    }

    // Initialize DP table
    dp = vector<vector<vector<int>>>(n+1, vector<vector<int>>(k+10, vector<int>(3, -1)));
    int fans = -1e18;
    if(s[0]=='A'){
        fans = max(fans, rec(1, k, 0));
        fans = max(fans, 1+rec(1, k, 1));
        fans = max(fans, rec(1, k, 2));
    }
    else if(s[0]=='B'){
        fans = max(fans, rec(1, k, 0));
        fans = max(fans, rec(1, k, 1));
        fans = max(fans, 1+rec(1, k, 2));
    }
    else if(s[0]=='C'){
        fans = max(fans, 1+rec(1, k, 0));
        fans = max(fans, rec(1, k, 1));
        fans = max(fans, rec(1, k, 2));
    }
    cout<<fans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
