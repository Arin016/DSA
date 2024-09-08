#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
vector<string> a;
vector<vector<int>> vis;

bool isvalid(int x, int y){
    return x>=0 and x<n and y>=0 and y<n and a[x][y] == '#';
}

int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};

vector<pair<int, int>> neighbours(int x, int y){
    vector<pair<int, int>> ans;
    for(int k=0; k<4; k++){
        int nx = x + dx[k], ny = y + dy[k];
        if(isvalid(nx, ny)){
            ans.push_back({nx, ny});
        }
    }
    return ans;
}

void dfs(int x, int y, int color){
    vis[x][y] = color;
    for(auto v : neighbours(x, y)){
        int i = v.first, j = v.second;
        if(!vis[i][j]){
            dfs(i, j, color);
        }
    }
}

void solve(){
    cin >> n;
    a.resize(n);
    vis.assign(n, vector<int>(n, 0));  // Initialize vis with size n x n filled with 0
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int color = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!vis[i][j] and a[i][j] == '#'){
                dfs(i, j, color);
                color++;
            }
        }
    }

    vector<int> area(color, 0), peri(color, 0);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(vis[i][j] > 0){
                area[vis[i][j]]++;
                for(int k = 0; k < 4; k++){
                    int nx = i + dx[k], ny = j + dy[k];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n || vis[nx][ny] != vis[i][j]){
                        //vis[nx][ny] != vis[i][j] if nx, ny is within the same cc then that wont increase perimeter
                        //we are using || becuase thats how wed be able to count the outer boundaries too
                        peri[vis[i][j]]++;
                    }
                }
            }
        }
    }

    int maxarea = 0, maxperi = 1e18;
    for(int i = 1; i < color; i++){
        if(area[i] > maxarea){
            maxarea = area[i];
            maxperi = peri[i];
        }
        else if(area[i] == maxarea){
            maxperi = min(maxperi, peri[i]);
        }
    }
    cout << maxarea << " " << maxperi << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}
