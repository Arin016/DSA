#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

// Minimum number of policemen to place in the graph such that the thief could be caught by any of them.

int n, m;
vector<vector<int>> g, grev;

vector<int> vis;
vector<int> toutOrder;

void dfs1(int node){
    vis[node] = 1;
    for(auto x : g[node]){
        if(!vis[x]){
            dfs1(x);
        }
    }
    toutOrder.push_back(node);  // Push after recursion (post-order)
}

void dfs2(int node, int scc){
    vis[node] = scc;
    for(auto x : grev[node]){
        if(!vis[x]){
            dfs2(x, scc);
        }
    }
}

void solve(){
    cin >> n >> m;
    g.resize(n+1);
    grev.resize(n+1);
    vis.assign(n+1, 0);
    
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        grev[y].push_back(x);
    }

    // First DFS to fill toutOrder
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs1(i);
        }
    }

    reverse(toutOrder.begin(), toutOrder.end());  // Reverse post-order after DFS1
    vis.assign(n+1, 0);  // Reset vis for the second DFS

    int scc = 1;
    for(auto x : toutOrder){
        if(!vis[x]){
            dfs2(x, scc);
            scc++;
        }
    }

    vector<vector<int>> sccc(scc);
    for(int i = 1; i <= n; i++){
        sccc[vis[i]].push_back(i);
    }
    //number of scc : 
    cout<<scc-1<<endl;
    for(int i=1;i<=n;i++){
        cout<<vis[i]<<" ";
    }
    cout<<endl;
    // Process SCCs (you can add additional logic here)
    //creating the condensed graph
    vector<vector<int>> cg;
    cg.resize(scc);
    vector<int> indegcg;
    indegcg.assign(scc, 0);
    for(int i=1;i<=n;i++){
        for(auto x:g[i]){
            if(vis[x]==vis[i])continue;
            else {
                cg[vis[i]].push_back(vis[x]);
                indegcg[vis[x]]++;
            }
        }
    }

    // //VS (to not have duplicate edges!!)

    // vector<set<int>> cg1;
    // cg1.resize(scc);

    // for(int i=1;i<=n;i++){
    //     for(auto x:g[i]){
    //         if(vis[x]==vis[i])continue;
    //         else cg1[vis[i]].insert(vis[x]);
    //     }
    // }
     
    // for(auto x:cg1){
    //     for(auto y:x){
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;
    // }

    //now we have a DAG in the condensed graph!
    //because we took off all the cycles!


    //now ans = nodes whose indegree = 0! becuase if we cover these nodes explicitly theyll take care of
    //all other nodes as all other ones would have indeg>0 so some or the other police will get there!

    int ans = 0;
    for(int i=1;i<scc;i++){
        if(indegcg[i]==0){
            ans++;
        }
    }
    cout<<ans<<endl;

    //once you convert it to dag you could solve DAG based problems too!
    //DP+DAG!! use recursive way to code else get the topo ordering and process the dp in tht order
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
