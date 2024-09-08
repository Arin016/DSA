#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

struct dsu {
    int ncmp;
    vector<int> par, size;
    
    void init(int n) {
        ncmp = n;
        par.resize(n+1);
        size.resize(n+1); // Renamed rank to size
        for(int i = 1; i <= n; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        if(x == par[x]) return x;
        return par[x] = find(par[x]); // Path compression
    }

    bool merge(int x, int y) {
        int xL = find(x);
        int yL = find(y);
        if(xL == yL) return false;
        if(size[xL] <= size[yL]) { // Attach smaller tree under larger
            par[xL] = yL;
            size[yL] += size[xL];
        } else {
            par[yL] = xL;
            size[xL] += size[yL];
        }
        ncmp--;
        return true;
    }
};

void solve() {
    // Add logic here
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}
