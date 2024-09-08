#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

//given a tree of n nodes and weighted edges, find the sum of path of Q different simple paths as queries
//values are on edges you have to push them onto nodes below them!
//keep such a value on root node that doesnt affect your operations on paths
//eg in sum its 0 in max its -1e9 and in min its 1e9
//#####and when you push values like this you dont include LCA node in your answer##### 

int n;
vector<vector<pair<int, int>>> g;
vector<vector<int>> nex, dp;
vector<int> depth, val;

//remember how to write this!
int F(int a, int b){
    return a+b;
}

void dfs(int node, int par, int d, int valpush){
    nex[node][0] = par;
    val[node] = valpush;
    dp[node][0] = val[node];
    depth[node] = d;
    for(int i=1;i<20;i++){
        nex[node][i] = nex[nex[node][i-1]][i-1];
        dp[node][i] = F(dp[node][i-1], dp[nex[node][i-1]][i-1]);
    }
    for(auto x:g[node]){
        if(x.first != par){
            dfs(x.first, node, d+1, x.second);
        }
    }
}

int pathagg(int u, int v){
    if(depth[v] > depth[u]){
        swap(u, v); //making sure u is lower!
    }
    int ans = 0;
    for(int i=19;i>=0;i--){
        if(((depth[u]-depth[v]) >> i) & 1){
            ans = F(ans, dp[u][i]);
            u = nex[u][i];
        }
    }
    // because dp[u][i] stores aggregate sum till (u+2^i)-1 so we manually have to include the last one
    if(u == v) return ans;  // no need to include LCA node
    for(int i=19;i>=0;i--){
        if(nex[u][i] != nex[v][i]){
            ans = F(ans, dp[u][i]);
            u = nex[u][i];
            ans = F(ans, dp[v][i]);
            v = nex[v][i];
        }
    }
    ans = F(ans, val[u]);
    ans = F(ans, val[v]);
    return ans; // do not add val[nex[u][0]] to exclude the LCA node
}

void solve(){
    cin >> n;
    g.resize(n+1);
    depth.resize(n+1);
    val.resize(n+1);
    nex.assign(n+1, vector<int>(20, 0));  
    dp.assign(n+1, vector<int>(20, 0));
    for(int i=0;i<n-1;i++){
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    dfs(1, 0, 0, 0);
    int q;
    cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        cout << pathagg(x, y) << endl;      
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
