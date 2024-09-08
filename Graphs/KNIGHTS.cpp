#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, sx, sy, fx, fy;

bool isvalid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n;
}

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

vector<pair<int, int>> neighbours(int x, int y){
    vector<pair<int, int>> ans;
    for(int k = 0; k < 8; k++){
        int nx = x + dx[k], ny = y + dy[k];
        if(isvalid(nx, ny)){
            ans.push_back({nx, ny});
        }
    }
    return ans;
}

vector<vector<int>> vis, dis;

void bfs(int xx, int yy){
    vis.assign(n, vector<int>(n, 0));
    dis.assign(n, vector<int>(n, 1e18));
    queue<pair<int, int>> q;
    dis[xx][yy] = 0;
    q.push({xx, yy});

    while(!q.empty()){
        auto cur = q.front();
        int curx = cur.first;
        int cury = cur.second;
        q.pop();
        if(vis[curx][cury]) continue;
        vis[curx][cury] = 1;

        for(auto x : neighbours(curx, cury)){
            int nx = x.first;
            int ny = x.second;
            if(dis[nx][ny] > dis[curx][cury] + 1){
                dis[nx][ny] = dis[curx][cury] + 1;
                q.push({nx, ny});
            }
        }
    }
}

void solve(){
    cin >> n >> sx >> sy >> fx >> fy;
    sx--, sy--, fx--, fy--;
    bfs(sx, sy);
    cout << dis[fx][fy] << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
