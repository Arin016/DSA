#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

//NON TRIVIAL!! (dp, prefixdp, prevocc) maintain these 3 things!

// dp[i] = # of distinct subsequences generated using ith index character which weren't seen before
//dpprefix[i] = sum of distinct subseq till now
//dp[i] = dpprefix[i-1] - dpprefix[lastseen[a[i]]-1];

void solve() {
    //reatch the video if any doubt exists!
    //draw the table for abaab and see for yourself ans = 13!
    string s;
    cin >> s;
    int n = s.length();
    int dp[n+1]; //cnt of unique subsequences ending at i
    memset(dp, 0, sizeof(dp));
    int dpprefix[n+1];
    memset(dpprefix, 0, sizeof(dpprefix));
    int prevocc[26];
    memset(prevocc, -1, sizeof(prevocc));
    dp[0] = 1; //empty string
    dpprefix[0] = 1;
    for(int i=1;i<=n;i++){ //according to table that vivek drew we had an empty string in the begining
        dp[i] = dpprefix[i-1]; //naya index ko inclucde karke kitne naya banenge? jitne pichle wale tak prefix summed up the utne!
        if(prevocc[s[i-1]-'a']!=-1){
            //to remove duplicates!
            int index = prevocc[s[i-1]-'a']-1;
            dp[i] -= dpprefix[index];
            // seen before, need to subtract the contribution from the previous occurrence
        }
        prevocc[s[i-1]-'a'] = i; // update the last occurrence
        dpprefix[i]=dpprefix[i-1]+dp[i]; //update the dpprefix
    }
    cout<<dpprefix[n] - 1<<endl; //not counting empty string
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
