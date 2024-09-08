#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m, k;
vector<vector<int>> a, na;
vector<vector<int>> vis, nvis;

int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};

// Check if a cell is within bounds and non-zero
bool isvalid(int x, int y){
    return x>=0 and x<n and y>=0 and y<m and a[x][y]!=0;
}

// Get valid neighboring cells with the same color
vector<pair<int, int>> neigh(int x, int y){
    vector<pair<int, int>> ans;
    for(int k=0;k<4;k++){
        int nx = x+dx[k], ny = y+dy[k];
        if(isvalid(nx, ny) and (a[x][y] == a[nx][ny])){
            ans.push_back({nx, ny});
        }
    }
    return ans;
}

// DFS to mark connected components
void dfs(int x, int y, int color){
    vis[x][y] = color;
    for(auto v : neigh(x, y)){
        int i = v.first, j = v.second;
        if(!vis[i][j]){
            dfs(i, j, color);
        }
    }
}

// DFS for removing the connected components and marking them zero
void ndfs(int x, int y, int color){
    na[x][y] = color;
    nvis[x][y] = 1;
    for(auto v : neigh(x, y)){
        int i = v.first, j = v.second;
        if(!nvis[i][j]){
            ndfs(i, j, color);
        }
    }
}

// Find and remove connected components of size at least K
bool findcmpszs(){
    bool found = false;
    int color = 1;
    vis.assign(n, vector<int>(m, 0));

    // Mark all connected components with DFS
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] and a[i][j] != 0){
                dfs(i, j, color);
                color++;
            }
        }
    }

    // Group cells by their connected component color
    vector<vector<pair<int, int>>> cc(color);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j]) {
                cc[vis[i][j]].push_back({i, j});
            }
        }
    }

    // Check if any connected component has size >= K
    for(int i=1; i<color; i++){
        if((int)(cc[i].size()) >= k){
            found = true;
            nvis.assign(n, vector<int>(m, 0));
            na = a;  // Initialize na to be equal to the current grid a
            for(auto& p : cc[i]){
                int x = p.first, y = p.second;
                if(!nvis[x][y]){
                    ndfs(x, y, 0);  // Mark these cells as 0
                }
            }
            a = na;  // Update the grid after removing components
        }
    }
    
    return found;
}

// Apply gravity to the grid, moving balls downward
void gravity(){
    for(int j=0; j<m; j++){
        int i = n-1, p = n-1;
        while(i >= 0){
            if(a[i][j] != 0){
                swap(a[i][j], a[p][j]);
                p--;
            }
            i--;
        }
    }
}

void solve(){
    cin >> n >> k;
    m = 10;
    a.resize(n, vector<int>(m, 0));
    na.resize(n, vector<int>(m, 0));

    // Input the grid
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char ch;
            cin >> ch;
            a[i][j] = (int)(ch - '0');
        }
    }
    na = a;

    // Keep removing components and applying gravity until no more changes
    while(findcmpszs()){
        gravity();
    }

    // Output the final grid
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << a[i][j];
        }
        cout << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}
