#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 10000

// ans(node) = when rooted at node, what's the value of dis(x, node)*a[x] where x lies in the subtree of node

vector<vector<int>> g;
vector<int> val, subtreeval, ans, dep;
int sum;
int total;

void in_dfs(int node, int par, int depth) {
    subtreeval[node] = val[node];
    dep[node] = depth;
    for (auto v : g[node]) {
        if (v != par) {
            in_dfs(v, node, depth + 1);
            subtreeval[node] += subtreeval[v];
        }
    }
}

void dfs(int node, int par) {
    if(par==0) ans[node] = total;
    else ans[node] = ans[par] + (sum-subtreeval[node]) - (subtreeval[node]);
    for (auto v : g[node]) {
        if (v != par) {
            dfs(v, node);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    g.clear();
    g.resize(n + 1);
    val.clear();
    val.resize(n + 1);
    subtreeval.clear();
    subtreeval.resize(n + 1);
    ans.clear();
    ans.resize(n + 1);
    dep.clear();
    dep.resize(n + 1);
    sum = 0;

    for (int i = 1; i <= n; i++) {
        cin >> val[i];
        sum += val[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    in_dfs(1, 0, 0);
    total = 0;
    for (int i = 1; i <= n; i++) {
        total += dep[i] * val[i];
    }
    dfs(1, 0);

    int min_cost = LLONG_MAX;
    int max_cost = LLONG_MIN;

    for (int i = 1; i <= n; i++) {
        min_cost = min(min_cost, ans[i]);
        max_cost = max(max_cost, ans[i]);
    }

    cout << max_cost << " " << min_cost << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}