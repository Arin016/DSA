#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
vector<string> a;
vector<pair<int, int>> M;
pair<int, int> A;


bool isvalid(int x, int y){
    return x>=0 and x<n and y>=0 and y<m and (a[x][y]!='#');
    //writing this exact same condition itself is IMP else it wont work, think why?
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

vector<vector<int>> visA, disA;
vector<vector<pair<int, int>>> parA;

void bfsA(int x, int y){
    visA.assign(n, vector<int>(m, 0));
    disA.assign(n, vector<int>(m, 1e18));
    parA.assign(n, vector<pair<int, int>>(m, {-1, -1}));
    queue<pair<int, int>> q;
    disA[x][y] = 0;
    parA[x][y] = {-1, -1};
    q.push({x, y});
    while(!q.empty()){
        auto cur = q.front();
        int curx = cur.first;
        int cury = cur.second;
        q.pop();
        if(visA[curx][cury])continue;
        visA[curx][cury] = 1;
        for(auto x:neighbours(curx, cury)){
            int nx = x.first, ny = x.second;
            if(disA[nx][ny]>disA[curx][cury]+1){
                disA[nx][ny] = disA[curx][cury]+1;
                parA[nx][ny] = {curx, cury};
                q.push({nx, ny});
            }
        }
    }
}

vector<vector<int>> visM, disM;

void bfsM(){
    visM.assign(n, vector<int>(m, 0));
    disM.assign(n, vector<int>(m, 1e18));
    queue<pair<int, int>> q;
    //we push monsters into the queue because we need shortest distance monster to each of the exits
    //and not shortest exit for each of the monster!!!!
    for(auto x:M){
        disM[x.first][x.second] = 0;
        q.push({x.first, x.second});
    } 
    while(!q.empty()){
        auto cur = q.front();
        int curx = cur.first;
        int cury = cur.second;
        q.pop();
        if(visM[curx][cury])continue;
        visM[curx][cury] = 1;
        for(auto x:neighbours(curx, cury)){
            int nx = x.first, ny = x.second;
            if(disM[nx][ny]>disM[curx][cury]+1){
                disM[nx][ny] = disM[curx][cury]+1;
                q.push({nx, ny});
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='M'){
                M.push_back({i, j});
            }
            else if(a[i][j]=='A'){
                A = {i, j};
            }
        }
    }

    bfsA(A.first, A.second);
    bfsM();
    //iterate over all the exits and check if person is closer to the exit than all the monsters(nearest monster)!
    int mindis = 1e18;
    pair<int, int> exit;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || i==n-1 || j==0 || j==m-1){
                if(a[i][j]!='#'){
                    if(disA[i][j]<disM[i][j]){
                        if(disA[i][j]<mindis){
                            mindis = disA[i][j];
                            exit = {i, j};
                        }   
                    }
                }
            }
        }
    }
    if(mindis==1e18)cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        cout<<mindis<<endl;
        vector<pair<int, int>> path;
        pair<int, int> cur = exit;
        while(cur!=A){
            path.push_back(cur);
            cur = parA[cur.first][cur.second];
        }
        path.push_back(A);
        reverse(path.begin(), path.end());

        string ans;
        for(int i=1;i<(int)(path.size());i++){
            for(int k=0;k<4;k++){
                int px = path[i-1].first, py = path[i-1].second;
                int nx = path[i].first, ny = path[i].second;
                if(px + dx[k] == nx && py + dy[k] == ny){
                    if(k==0){
                        ans+='U';
                    }
                    else if(k==1){
                        ans+='D';
                    }
                    else if(k==2){
                        ans+='R';
                    }
                    else{
                        ans+='L';
                    }
                    break;
                }
            }
        }
        cout<<ans<<endl;
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
