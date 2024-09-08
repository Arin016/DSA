#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
vector<vector<int>> a;
map<pair<int, int>, int> iswall;

bool isvalid(int x, int y){
    return x>=0 and x<n and y>=0 and y<m and iswall[{x, y}]!=1;
}

int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, -1, +1};

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

void dfs(int x, int y, int color){
    vis[x][y] = color;
    for(auto v:neighbours(x, y)){
        int i = v.first, j = v.second;
        if(!vis[i][j]){
            dfs(i, j, color);
        }
    }
}

void solve(){
    cin>>n>>m;
    a.clear();
    vis.clear();
    iswall.clear();
    a.assign(n+1, vector<int>(m+1, 0));
    vis.assign(n+1, vector<int>(m+1, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]==1)iswall[{i, j}]=1;
        }
    }
    int color = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] and iswall[{i, j}]==0){
                dfs(i, j, color);
                color++;
            }
        }
    }
    vector<vector<pair<int, int>>> cc;
    cc.resize(color);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cc[vis[i][j]].push_back({i, j});
        }
    }
    // for(int i=1;i<cc.size();i++){
    //     cout<<cc[i].size()<<" ";
    // }
    // cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(iswall[{i, j}]){
                cout<<1<<" ";
            }
            else{
                if(cc[vis[i][j]].size()==1)cout<<0<<" ";
                else cout<<cc[vis[i][j]].size()<<" ";
            }
        }
        cout<<endl;
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
