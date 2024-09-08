#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
vector<vector<int>> g;
vector<int> indeg;
vector<int> topo;
void kahns(){
    priority_queue<int> pq;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            pq.push(-i);
        }
    }
    while(!pq.empty()){
        auto cur = -pq.top();
        pq.pop();
        topo.push_back(cur);
        for(auto x:g[cur]){
            indeg[x]--;
            if(indeg[x]==0){
                pq.push(-x);
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    indeg.assign(n+1, 0);
    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        indeg[b]++;
    }
    kahns();
    if(topo.size()==n){
        for(auto x:topo){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    else cout<<-1<<endl;
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
