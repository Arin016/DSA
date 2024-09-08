#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

struct dsu {
    int cmp;
    vector<int> par, size;

    void init(int n) {
        cmp = n;
        par.resize(n+1);
        size.resize(n+1);
        for(int i = 1; i <= n; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        if(x == par[x]) return x;
        else return par[x] = find(par[x]);
    }

    bool merge(int x, int y) {
        int xL = find(x);
        int yL = find(y);
        if(xL == yL) return 0;
        if(size[xL] <= size[yL]) {
            par[xL] = yL;
            size[yL] += size[xL];
        } else {
            par[yL] = xL;
            size[xL] += size[yL];
        }
        cmp--;
        return 1;
    }

    int getsz() {
        return cmp;
    }
};

int n, m, q;
vector<pair<int, int>> edges;
vector<pair<int, int>> queries;

void solve() {
    cin >> n >> m >> q;
    dsu d;
    d.init(n);
    
    edges.resize(m);
    for(int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    vector<int> delete_queries;
    for(int i = 0; i < q; i++) {
        int ch, x = 0;
        cin >> ch;
        if(ch == 1) {
            cin >> x;
            delete_queries.push_back(x - 1); // Store index to delete
        }
        queries.push_back({ch, x});
    }

    // Mark edges to be deleted
    vector<bool> active(m, true);
    for(auto v : delete_queries) {
        active[v] = false;
    }

    // Process the active edges
    for(int i = 0; i < m; i++) {
        if(active[i]) {
            d.merge(edges[i].first, edges[i].second);
        }
    }

    vector<int> ans;
    for(int i = q - 1; i >= 0; i--) {
        int ch = queries[i].first;
        int x = queries[i].second;
        if(ch == 1) {
            d.merge(edges[x-1].first, edges[x-1].second);
        } else if(ch == 2) {
            ans.push_back(d.getsz());
        }
    }

    reverse(ans.begin(), ans.end());
    for(auto v : ans) {
        cout << v << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}
