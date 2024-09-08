#include<bits/stdc++.h>
using namespace std;
#define int long long

int mod = 1e9+7;

int n;
vector<vector<int>> g;
vector<int> parent, depth;

void dfs(int node, int par, int d){
    depth[node] = d;
    parent[node] = par;
    for(auto x: g[node]){
        if(x != par){ // x != par to avoid counting the parent node
            dfs(x, node, d+1);
        }
    }
}

void solve(){
    cin >> n;
    
    g.assign(n + 1, vector<int>());
    parent.assign(n + 1, -1);
    depth.assign(n + 1, 0);

    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }   

    // diameter of a tree is the maximum distance between any 2 nodes
    //diameter of a tree is maximum distance between any 2 nodes
    //diameter of a graph is for any u, v pair such that shortest distance between u, v is the largest
    //dfs from a random node X find the farthest node Y and dfs from Y and find the farthest node Z 
    //Y-Z is a diameter
    int X = 1;
    dfs(X, 0, 0);

    int Y = X;
    int dis1 = 0;
    for(int i = 1; i <= n; i++){
        if(depth[i] > dis1){
            dis1 = depth[i];
            Y = i;
        }
    }

    dfs(Y, 0, 0);

    int dis2 = 0;
    for(int i = 1; i <= n; i++){
        if(depth[i] > dis2){
            dis2 = depth[i];
        }
    }
    
    cout << dis2 << '\n';  // Output the diameter of the tree

    //start at some point and can end at some other point whats the min time? you have to cover all nodes
    //if it were like start == end then ans would always be 2*E but, here we need not end at start
    //(2*E - path) minimise thus maximise path thus path = diameter
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
