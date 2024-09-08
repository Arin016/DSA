#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<vector<int>> g;
vector<int> parent, subtreesz;

void dfs(int node, int par){
    parent[node] = par;
    subtreesz[node] = 1;
    for(auto x : g[node]){
        if(x != par){
            dfs(x, node);
            subtreesz[node] += subtreesz[x];
        }
    }
}


int dfscentroid(int node){
    for(auto x : g[node]){
        if(x != parent[node] && subtreesz[x] > n / 2){
            return dfscentroid(x);  // Move to the child with a larger subtree size
        }
    }
    return node;
}

void solve(){
    cin >> n;
    g.resize(n + 1);
    parent.resize(n + 1);
    subtreesz.resize(n + 1);
    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }  
    dfs(1, -1);  // Initialize the subtree sizes
    cout << dfscentroid(1) << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
