#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

//any path in a tree can be decomposed from its LCA
// nex[x][i] --> what node would you reach to if you take a jump of 2^i from x?
// dp[x][i] --> what is the aggregate value of nodes in [x.....x+2^i)??  * last one excluded
//dp(x, i) = GCD(dp(x, i-1), dp(nex(x, i-1), i-1))
//the same idea could be extended to GCD, sum, max, min, xor

int n;
vector<vector<int>> g;
vector<vector<int>> nex, dp;
vector<int> depth, val;

//remember how to write this!
int F(int a, int b){
    if(b==0)return a;
    return F(b, a%b);
}

void dfs(int node, int par, int d){
    nex[node][0] = par;
    dp[node][0] = val[node];
    depth[node] = d;
    for(int i=1;i<20;i++){
        nex[node][i] = nex[nex[node][i-1]][i-1];
        dp[node][i] = F(dp[node][i-1], dp[nex[node][i-1]][i-1]);
    }
    for(auto x:g[node]){
        if(x!=par){
            dfs(x, node, d+1);
        }
    }
}

int pathagg(int u, int v){
    if(depth[v]>depth[u]){
        swap(u, v); //making sure u is lower!
    }
    int ans = 0;
    for(int i=19;i>=0;i--){
        if(((depth[u]-depth[v])>>i)&1){
            ans = F(ans, dp[u][i]);
            u = nex[u][i];
        }
    }
    //because dp[u][i] stores aggregate gcd till (u+2^i)-1 so we manually have to include the last one
    if(u==v)return F(ans, val[u]);
    for(int i=19;i>=0;i--){
        if(nex[u][i]!=nex[v][i]){
            ans = F(ans, dp[u][i]);
            u = nex[u][i];
            ans = F(ans, dp[v][i]);
            v = nex[v][i];
        }
    }
    //this is imp! because dp[x][i] stores aggregate only till [x...x+2^i-1] so we have to manually add the last
    //element to the aggregate!
    ans = F(ans, val[u]);
    ans = F(ans, val[v]);
    return F(ans, val[nex[u][0]]);
}

void solve(){
    cin>>n;
    g.resize(n+1);
    depth.resize(n+1);
    val.resize(n+1);
    nex.assign(n+1, vector<int>(21, 0));
    dp.assign(n+1, vector<int>(21, 0));
    for(int i=1;i<=n;i++)cin>>val[i];
    for(int i=0;i<n-1;i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0, 0);
    int q;
    cin>>q;
    while(q--){
        int x, y;
        cin>>x>>y;
        cout<<pathagg(x, y)<<endl;      
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        g.clear();
        depth.clear();
        nex.clear();
        dp.clear();
        solve();
    }
}
