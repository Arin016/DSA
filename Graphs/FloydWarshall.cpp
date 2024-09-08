#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


//length of the shortest cycle --> take off dis[i][i] = 1e9 and run floydwarshall and take min of all dis[i][i]
//diameter of a graph --> take max from dis[i][j] and it shuldnt be equal to 1e18

const int N = 1e3+100;
int dis[N][N];
int par[N][N];
//par[i][j] = tells you the j's parent on the path from i to j

void printpath(int i, int j){
    if(i!=j){
        printpath(i, par[i][j]);
    }
    cout<<j<<" ";
}
void solve(){
    int n, m;
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==j)dis[i][j] = 0;
            else dis[i][j] = 1e18;
            par[i][j] = i;
        }
    }
    for(int i=0;i<m;i++){
        int x, y, w;
        cin>>x>>y>>w;
        dis[x][y] = min(dis[x][y], w);
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][j] > dis[i][k]+dis[k][j]){
                    dis[i][j] = dis[i][k]+dis[k][j];
                    par[i][j] = par[k][j];
                }
                // dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
                
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
