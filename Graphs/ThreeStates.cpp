#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

//there's an island 1, 2, 3, #, . based problem in which edge from 1---2 per say is cost 0 but from empty to empty
//or empty to a number its cost 1
//dis[a][i][j]
//Multi sourse BFS from a = 1's component, 2's and 3's
//dis[1][x][y] = tells us min distance of node x, y from any of "1"

//then ans = for all x and y dis[1][x][y] + dis[2][x][y] + dis[3][x][y] - 2 if (a[x][y]=='.')

int n, m;
vector<string> a;
vector<vector<int>> vis1, dis1;
vector<vector<int>> vis2, dis2;
vector<vector<int>> vis3, dis3;
vector<pair<int, int>> one, two, three; 

int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};

bool isvalid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m && a[x][y] != '#';
}

vector<pair<pair<int, int>, int>> neigh(int x, int y) {
    vector<pair<pair<int, int>, int>> ans;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (isvalid(nx, ny)) {
            if (a[nx][ny] == '.') {
                ans.push_back({{nx, ny}, 1});
            } else {
                ans.push_back({{nx, ny}, 0});
            }
        }
    }
    return ans;
}

void mbfs1(){
    vis1.assign(n, vector<int>(m, 0));
    dis1.assign(n, vector<int>(m, 1e18));
    deque<pair<int, int>> q;
    for(auto x : one){
        dis1[x.first][x.second] = 0;
        q.push_back(x);
    }
    while(!q.empty()){
        auto cur = q.front();
        q.pop_front();
        int curx = cur.first, cury = cur.second;
        if (vis1[curx][cury]) continue;
        vis1[curx][cury] = 1;
        for(auto v : neigh(curx, cury)){
            int nx = v.first.first, ny = v.first.second;
            int wt = v.second;
            if (dis1[nx][ny] > dis1[curx][cury] + wt){
                dis1[nx][ny] = dis1[curx][cury] + wt;
                if(wt) q.push_back({nx, ny});
                else q.push_front({nx, ny});
            }
        }
    }
}

void mbfs2(){
    vis2.assign(n, vector<int>(m, 0));
    dis2.assign(n, vector<int>(m, 1e18));
    deque<pair<int, int>> q;
    for(auto x : two){
        dis2[x.first][x.second] = 0;
        q.push_back(x);
    }
    while(!q.empty()){
        auto cur = q.front();
        q.pop_front();
        int curx = cur.first, cury = cur.second;
        if (vis2[curx][cury]) continue;
        vis2[curx][cury] = 1;
        for(auto v : neigh(curx, cury)){
            int nx = v.first.first, ny = v.first.second;
            int wt = v.second;
            if (dis2[nx][ny] > dis2[curx][cury] + wt){
                dis2[nx][ny] = dis2[curx][cury] + wt;
                if(wt) q.push_back({nx, ny});
                else q.push_front({nx, ny});
            }
        }
    }
}

void mbfs3(){
    vis3.assign(n, vector<int>(m, 0));
    dis3.assign(n, vector<int>(m, 1e18));
    deque<pair<int, int>> q;
    for(auto x : three){
        dis3[x.first][x.second] = 0;
        q.push_back(x);
    }
    while(!q.empty()){
        auto cur = q.front();
        q.pop_front();
        int curx = cur.first, cury = cur.second;
        if (vis3[curx][cury]) continue;
        vis3[curx][cury] = 1;
        for(auto v : neigh(curx, cury)){
            int nx = v.first.first, ny = v.first.second;
            int wt = v.second;
            if (dis3[nx][ny] > dis3[curx][cury] + wt){
                dis3[nx][ny] = dis3[curx][cury] + wt;
                if(wt) q.push_back({nx, ny});
                else q.push_front({nx, ny});
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '1') one.push_back({i, j});
            else if (a[i][j] == '2') two.push_back({i, j});
            else if (a[i][j] == '3') three.push_back({i, j});
        }
    }
    mbfs1();
    mbfs2();
    mbfs3();
    int ans = 1e18;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != '#') {
                int val = dis1[i][j] + dis2[i][j] + dis3[i][j];
                if (a[i][j] == '.') val -= 2;  // Cost adjustment
                ans = min(ans, val);
            }
        }
    }
    if (ans == 1e18) cout << -1 << endl;  // Return -1 if no solution is found
    else cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t--){
        solve();
    }
}
