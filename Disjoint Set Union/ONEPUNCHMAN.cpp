#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
vector<string> a;

bool isvalid(int x, int y){
    return x >= 0 and x < n and y >= 0 and y < m;
}

int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};

vector<pair<pair<int, int>, int>> neighbours(int x, int y){
    vector<pair<pair<int, int>, int>> ans;
    for(int k = 0; k < 4; k++){
        int nx = x + dx[k], ny = y + dy[k];
        if(isvalid(nx, ny)){
            if(a[nx][ny] == '.'){
                ans.push_back({{nx, ny}, 0});
            } else if(a[nx][ny] == '#'){
                for(int xx = -1; xx <= 1; xx++){
                    for(int yy = -1; yy <= 1; yy++){
                        if(isvalid(nx + xx, ny + yy)){ 
                            ans.push_back({{nx + xx, ny + yy}, 1});
                        }
                    }
                }
            }
        }
    }
    return ans;
}

vector<vector<int>> vis, dis;
void bfs01(int x, int y){
    vis.assign(n+1, vector<int>(m+1, 0));  
    dis.assign(n+1, vector<int>(m+1, 1e18));  
    deque<pair<int, int>> q;
    dis[x][y] = 0;
    q.push_front({x, y});
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop_front();
        int curx = cur.first, cury = cur.second;
        if(vis[curx][cury]) continue;
        vis[curx][cury] = 1;
        
        for(auto v : neighbours(curx, cury)){
            int nx = v.first.first, ny = v.first.second;
            int wt = v.second;
            if(dis[nx][ny] > dis[curx][cury] + wt){
                dis[nx][ny] = dis[curx][cury] + wt;
                if(wt) q.push_back({nx, ny});
                else q.push_front({nx, ny});
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    a.resize(n+1);  
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    bfs01(0, 0); 
    
    cout << dis[n-1][m-1] << endl;
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
