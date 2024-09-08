#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
//ancestral path property dp

//number of possible valid assignments such that gcd of all paths==1?

//the path from root to parent must have gcd == 1 and the subtree of current node must have gcd==1
 
//dp(node, gcdtillparent) = summation(j)(1 to m)(product(x)(all childs)(dp(x, gcd(gcdtillparent, gcd(gcdtillparent, j)))))

//dp(node, G) = no of ways you could place colors in node's subtree with gcd till now from parent as G
int n, m;
vector<int> g[1000100];

int gcd(int a, int b){
    if(b==0)return a;
    return gcd(b, a%b);
}

//no need to cache par as it wouldnt change wrt to a node when the tree is rooted
int dp[1000100][22];

// g[node].size()==0 LMAO when n=1 and theres only one node that is leaf!

int rec(int node, int par, int G){
    //base case
    if((g[node].size()==1 and par!=0) || g[node].size()==0){ //if node is leaf
        int cnt = 0;
        for(int color=1;color<=m;color++){
            if(gcd(G, color)==1)cnt++;
        }
        return dp[node][G] = cnt;
    }
    //cache check
    if(dp[node][G]!=-1)return dp[node][G];
    //compute
    int fans = 0;
    for(int color=1;color<=m;color++){
        int ans = 1;
        for(auto x:g[node]){
            if(x!=par){
                ans *= rec(x, node, gcd(G, color));
                ans %= mod; // Include modulo operation to prevent overflow
            }
        }
        fans += ans;
        fans %= mod; // Include modulo operation to prevent overflow
    }
    //save and return
    return dp[node][G] = fans;
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        g[i].clear();
    }
    memset(dp, -1, sizeof(dp));
    
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    int result = rec(1, 0, 0); // Start rec from node 1 with GCD 0
    cout << result << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--){
        solve();
    }
}
