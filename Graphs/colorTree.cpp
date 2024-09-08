#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
vector<vector<int>> g;

void solve(){
    cin>>n;
    g.resize(n+1);
    for(int i=0;i<n-1;i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int maxi = 0;
    for(int i=1;i<=n;i++){
        maxi = max(maxi, (int)(g[i].size()));
    }
    cout<<maxi+1<<endl;
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
