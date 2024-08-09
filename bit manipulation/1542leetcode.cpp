#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define F first 
#define S second 
#define PB push_back 
#define endl "\n"
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define setpre(x, n) fixed << setprecision(x) << n
using lli = long long;
const lli INF = LLONG_MAX >> 1;
const lli M = 1000000007;
#define int long long


class Solution {
public:
    int longestAwesome(string s) {
        int dp[1<<(10)];
        for(int i=0;i<(1<<10);i++)dp[i] = 1e9;
        int ans = 1;
        int mask = 0;
        dp[0] = -1;
        for(int i=0;i<s.size();i++){
            mask^=(1<<(s[i]-'0'));
            dp[mask] = min(dp[mask], i);
            ans = max(ans, i-dp[mask]); //even
            for(int j=0;j<10;j++){ //odd
                ans = max(ans, i-dp[mask^(1<<j)]);
            }
        }
        return ans;
    }
};