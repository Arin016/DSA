//no of diameters??
//centre of a tree --> centre of a chosen diameter
//there can be 2 centre if diameter is made of even no of nodes
//all the diameters pass through the same centre?  yes its fixed for a tree! for all diameters
#include <bits/stdc++.h>
using namespace std;
#define int long long


vector<int> g[200200];
int dep[200200];
int par[200200];
bool isleaf[200200];
int subtreesz[200200];
int numchild[200200];

int d;
int cnt=0, cnt1=0;

void dfs(int node, int parent, int depth){
    dep[node] = depth;
    par[node] = parent;
    //counting the nodes in a subtree with depth = d/2-1
    if(depth==d/2-1)cnt++;
    if(depth==d/2)cnt1++;
    numchild[node] = 0;
    subtreesz[node] = 1; //set this value by default
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
    dfs(1, 0, 0);
    int ind1 = 1;
    for(int i=2;i<=n;i++){
        if(dep[i]>dep[ind1]){
            ind1 = i;
        }
    }
    dfs(ind1, 0, 0);
    int ind2 = 1;
    for(int i=2;i<=n;i++){
        if(dep[i]>dep[ind2]){
            ind2 = i;
        }
    }
    d = dep[ind2]-dep[ind1];

    int centre1, centre2;

    vector<int> path;
    int cur = ind2;
    while(cur!=ind1){
        path.push_back(cur);
        cur = par[cur];
    }
    path.push_back(ind1);
    reverse(path.begin(), path.end());

    if(path.size()==1){
        cout<<1<<endl;
        return;
    }
    if(path.size()%2==1){
        
        centre1 = path[path.size()/2];
        
        vector<int> ans;
        for(auto x:g[centre1]){
            cnt=0;
            dfs(x, centre1, 0);
            ans.push_back(cnt);
        }


        int tot=0;
        for(auto x:ans)tot+=x;
        int sol=0;
        for(auto x:ans){
            sol+=(tot-x)*x;
        }
        cout<<sol/2<<endl;

    }
    else{
        int x1=0, x2=0;
        centre1 = path[path.size()/2];
        centre2 = path[path.size()/2-1];
        // cout<<centre1<<" "<<centre2<<endl;
        cnt1=0;
        dfs(centre1, centre2, 0);
        x1+=cnt1;
        cnt1=0;
        dfs(centre2, centre1, 0);
        x2+=cnt1;
        cout<<x1*x2<<endl;
    }
    //trick : dfs(x1, x2, 0) if i want my dfs to start from x1 and never go into x2 ill set x2 to be parent of x1

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