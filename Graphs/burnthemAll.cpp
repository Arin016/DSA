#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
#define int long long
#define F first
#define S second
using state = pair<int, int>;
int n,m,st;
vector<int> dis;
vector<int> vis;
vector<vector<state>> g;
vector<pair<state, int>> edge;

void djikstra(int sc){
    dis[sc] = 0;
    priority_queue<state> pq;
    pq.push(make_pair(-0,sc));
    // node.second = the node itself which is at a distnace of 
    // node.fisrt from the start node
    while (!pq.empty())
    {
        state node = pq.top();
        pq.pop();

        if(vis[node.S]) continue;
        vis[node.S] = 1;

        for(auto neigh:g[node.S]){
            int ney = neigh.first;
            int wt = neigh.second;
            if(dis[ney] > dis[node.second]+wt){
                dis[ney]=dis[node.second]+wt;
                pq.push(make_pair(-dis[ney], ney));
            }
        }
    }
    
}

void printer(vector<vector<int>> xx){
    for(auto v:xx){
        for(auto u:v){
            cout<<u<<"\t";
        }
        cout<<"\n";
    }   
    cout<<endl;
}

void solve() {
    cin>>n>>m;
    dis.assign(n+1,1e18);
    vis.assign(n+1,0);
    g.resize(n+1);
    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edge.push_back({{a, b},c});
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    cin>>st;
    djikstra(st);
    int t=-1e18;
    //lets say it burns at t instant then (t-A) + (t-B) = X
    //t = (X+A+B)/2
    //10*t = (X+A+B)*5
    for(auto x:edge){
    	t = max(t, (dis[x.F.F]+dis[x.F.S]+x.S)*5);
    }
    cout<<t<<endl;
    
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t = 1;
    //cin >> _t;
    while (_t--)
    {
        solve();
    }

    return 0;
}