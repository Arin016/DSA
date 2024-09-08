#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

//kahns algorithm!

int n, m;
vector<vector<int>> g;
vector<int> indeg;
vector<int> topo;

void kahns(){
    priority_queue<int> q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            q.push(-i);
        }
    }
    while(!q.empty()){
        auto cur = -q.top();
        topo.push_back(cur);
        q.pop();
        for(auto x:g[cur]){
            indeg[x]--;
            if(indeg[x]==0){
                q.push(-x);
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    indeg.assign(n+1, 0);
    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        indeg[y]++;
    }
    kahns();
    for(auto x:topo){
        cout<<x<<" ";
    }
    cout<<endl;
    //if graph has a cycle then (topo.size()!=n)
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
