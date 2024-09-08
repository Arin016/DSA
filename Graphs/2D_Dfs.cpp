#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
vector<string> a;

bool isvalid(int x, int y){
    return x>=0 and x<n and y>=0 and y<m and a[x][y]=='.';
}

int dx[] = {-1, +1, 0, 0};
int dy[] = {0, 0, +1, -1};

vector<pair<int, int>> neighbours(int x, int y){
    vector<pair<int, int>> ans;
    for(int k=0;k<4;k++){
        int nx = x+dx[k], ny = y+dy[k];
        if(isvalid(nx, ny)){
            ans.push_back({nx, ny});
        }
    }
    return ans;
}

vector<vector<int>> vis;

void dfs(int x, int y){
    vis[x][y] = 1;
    for(auto v:neighbours(x, y)){
        int i = v.first, j = v.second;
        if(!vis[i][j]){
            dfs(i, j);
        }
    }
}

void solve(){
    cin>>n>>m;
    a.resize(n+1);
    vis.assign(n+1, vector<int>(m+1, 0));
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ncmp = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] and a[i][j]=='.'){
                dfs(i, j);
                ncmp++;
            }
        }
    }
    cout<<ncmp<<endl;
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
