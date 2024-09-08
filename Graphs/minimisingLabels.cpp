#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
vector<vector<int>> rg;
vector<int> outdeg;
vector<int> topo;

void kahns(){
    priority_queue<int> pq;
    for(int i=1;i<=n;i++){
        if(outdeg[i]==0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        topo.push_back(cur);
        for(auto x:rg[cur]){
            outdeg[x]--;
            if(outdeg[x]==0){
                pq.push(x);
            }
        }
    }
}

//the normal indeg logic fails when the graph is disconneted!
// 4 nodes 2 edges
// 4 1
// 2 3
//og algo - 4 1 2 3
//correct ans - 2 3 4 1

//maximum nodes ko maximum number dena hai jab reverse mein kar raha hai tab!
void solve(){
    cin>>n>>m;
    rg.resize(n+1);
    outdeg.assign(n+1, 0);
    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        rg[y].push_back(x);
        outdeg[x]++;
    }
    kahns();
    map<int, int> mp;
    int i = n;
    for(auto x:topo){
        mp[x] = i;
        i--;
    }
    for(int i=1;i<=n;i++){
        cout<<mp[i]<<" ";
    }
    cout<<endl;
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
