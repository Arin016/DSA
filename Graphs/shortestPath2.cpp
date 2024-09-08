#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    int n, m, q;
    cin>>n>>m>>q;
    int dis[n+1][n+1];
    int par[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)dis[i][j] = 0;
            else dis[i][j] = 1e18;
            par[i][j] = i;
        }
    }
    for(int i=0;i<m;i++){
        int a, b, c;
        cin>>a>>b>>c;
        dis[a][b] = min(dis[a][b], c);
        dis[b][a] = min(dis[b][a], c);
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j] = dis[i][k]+dis[k][j];
                    par[i][j] = par[k][j];
                }
            }
        }
    }
    while(q--){
        int a, b;
        cin>>a>>b;
        if(dis[a][b]==1e18)cout<<-1<<endl;
        else cout<<dis[a][b]<<endl;
    }
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
