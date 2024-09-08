#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

//####jiske samne """any""" hai usko supernode banana hai!!!!###
int n, m;
vector<vector<int>> a;
vector<pair<int, int>> ones;

bool isvalid(int x, int y){
    return x >= 0 and x < n and y >= 0 and y < m;
}

int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};

vector<pair<int, int>> neighbours(int x, int y){
    vector<pair<int, int>> ans;
    for(int k = 0; k < 4; k++){
        int nx = x + dx[k], ny = y + dy[k];
        if(isvalid(nx, ny)){
            ans.push_back({nx, ny});
        }
    }
    return ans;
}

vector<vector<int>> vis, dis;
void MBFS(){
    vis.assign(n, vector<int>(m, 0));
    dis.assign(n, vector<int>(m, 1e18));
    queue<pair<int, int>> q;
    for(auto x : ones){
        dis[x.first][x.second] = 0;
        q.push(x);
    }
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int curx = cur.first, cury = cur.second;
        if(vis[curx][cury]) continue;
        vis[curx][cury] = 1;
        for(auto v : neighbours(curx, cury)){
            int nx = v.first, ny = v.second;
            if(dis[nx][ny] > dis[curx][cury] + 1){
                dis[nx][ny] = dis[curx][cury] + 1;
                q.push({nx, ny});
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    a.resize(n, vector<int>(m, 0));
    ones.clear();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j]) ones.push_back({i, j});
        }
    }
    MBFS();
    int maxi = 0;
    pair<int, pair<int, int>> ans;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 0){
                maxi = max(maxi, dis[i][j]);
                ans = max(ans, {dis[i][j], {i, j}}); //NEW WAY!!!
            }
        }
    }
    cout<<ans.first<<endl;
    cout<<ans.second.first<<" "<<ans.second.second<<endl;
    cout << maxi << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
