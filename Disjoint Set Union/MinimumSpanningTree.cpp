#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

// MST using kruskals algorithm!

// a network of city, ci cost to repair a hospital and di cost to repair a road, min cost 
//for every city to be connecetd to a hospital either by having a local hospital or a path
//to some other hospital

//make a hypothetical node C and put those node weights on the edge C---ci and then get MST

struct dsu{
    int cmp;
    vector<int> par, size;

    void init(int n){
        cmp = n;
        par.resize(n+1);
        size.resize(n+1);
        for(int i=1; i<=n; i++){
            par[i] = i;
            size[i] = 1;
        }
    }

    int find(int x){
        if(x == par[x]) return x;
        return par[x] = find(par[x]); // path compression
    }

    bool merge(int x, int y){
        int xL = find(x);
        int yL = find(y);
        if(xL == yL) return false;
        // rank compression
        if(size[xL] <= size[yL]){
            par[xL] = yL;
            size[yL] += size[xL];
        } else {
            par[yL] = xL;
            size[xL] += size[yL];
        }
        cmp--;
        return true;
    }
};

void solve(){
    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> edges;
    dsu d;
    d.init(n + 1); // including the hypothetical node C

    vector<int> ci(n + 1); // cost to repair a hospital
    for(int i = 1; i <= n; i++){
        cin >> ci[i];
        edges.push_back({ci[i], {i, n + 1}}); // edge from city i to hypothetical node C
    }

    for(int i = 0; i < m; i++){
        int u, v, di;
        cin >> u >> v >> di;
        edges.push_back({di, {u, v}}); // road between city u and city v
    }

    sort(edges.begin(), edges.end()); // sort edges by cost

    int total_cost = 0;

    for(auto& edge : edges){
        int w = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if(d.merge(u, v)){
            total_cost += w;
        }
    }

    cout << total_cost << "\n";
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
