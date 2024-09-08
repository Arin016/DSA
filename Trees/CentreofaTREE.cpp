#include <bits/stdc++.h>
using namespace std;
#define int long long


vector<int> g[200200];
int dep[200200];
int par[200200];
bool isleaf[200200];
int subtreesz[200200];
int numchild[200200];

void dfs(int node, int parent, int depth){
    dep[node] = depth;
    par[node] = parent;
    numchild[node] = 0;
    subtreesz[node] = 1;
    for(auto x:g[node]){
        if(x!=parent){
            numchild[node]++;
            dfs(x, node, depth+1);
            subtreesz[node]+=subtreesz[x];
        }
    }
    if(numchild[node]==0)isleaf[node]=1;

}

void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int X = 1;
    dfs(X, 0, 0);
    int Y = 1;
    for(int i=2;i<=n;i++){
        if(dep[i]>dep[Y]){
            Y = i;
        }
    }
    dfs(Y, 0, 0);
    int Z = 1;
    for(int i=2;i<=n;i++){
        if(dep[i]>dep[Z]){
            Z = i;
        }
    }
    vector<int> path;
    int cur = Z;
    while(cur!=Y){
        path.push_back(cur);
        cur = par[cur];
    }
    path.push_back(Y);
    reverse(path.begin(), path.end());
    if(path.size()%2){
        cout<<path[path.size()/2]<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    // cout<<dep[Z]-dep[Y]<<endl;

}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}