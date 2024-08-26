#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int n = 7;
bool visited[8][8];
string s;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isvalid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int rec(int i, int j, int level) {
    // base case
    if (i == n - 1 && j == 0) { // If you've reached the bottom left corner
        if (level == n * n - 1) { // Whole string is processed
            return 1;
        }
        return 0;
    }
    //pruning
    //hitting the bottom edge
    if(i==n-1 and ((isvalid(i, j+1) and !visited[i][j+1] and isvalid(i, j-1) and !visited[i][j-1]) or (isvalid(i, j+1) and visited[i][j+1] and isvalid(i, j-1) and visited[i][j-1]))){
        return 0;
    }
    //hitting the top edge
    if(i==0 and ((isvalid(i, j+1) and !visited[i][j+1] and isvalid(i, j-1) and !visited[i][j-1]) or (isvalid(i, j+1) and visited[i][j+1] and isvalid(i, j-1) and visited[i][j-1]))){
        return 0;
    }
    //hitting the right edge
    if(j==n-1 and ((isvalid(i+1, j) and !visited[i+1][j] and isvalid(i-1, j) and !visited[i-1][j]) or (isvalid(i+1, j) and visited[i+1][j] and isvalid(i-1, j) and visited[i-1][j]))){
        return 0;
    }
    //hitting the left edge
    if(j==0 and ((isvalid(i+1, j) and !visited[i+1][j] and isvalid(i-1, j) and !visited[i-1][j]) or (isvalid(i+1, j) and visited[i+1][j] and isvalid(i-1, j) and visited[i-1][j]))){
        return 0;
    }
    //compute
    int ans = 0;
    
    // recursive case
    if (s[level] == 'L') {
        int nx = i, ny = j - 1;
        if (isvalid(nx, ny) && !visited[nx][ny]) {
            visited[nx][ny] = 1;
            ans += rec(nx, ny, level + 1);
            visited[nx][ny] = 0;
        }
    }
    else if (s[level] == 'R') {
        int nx = i, ny = j + 1;
        if (isvalid(nx, ny) && !visited[nx][ny]) {
            visited[nx][ny] = 1;
            ans += rec(nx, ny, level + 1);
            visited[nx][ny] = 0;
        }
    }
    else if (s[level] == 'U') {
        int nx = i - 1, ny = j;
        if (isvalid(nx, ny) && !visited[nx][ny]) {
            visited[nx][ny] = 1;
            ans += rec(nx, ny, level + 1);
            visited[nx][ny] = 0;
        }
    }
    else if (s[level] == 'D') {
        int nx = i + 1, ny = j;
        if (isvalid(nx, ny) && !visited[nx][ny]) {
            visited[nx][ny] = 1;
            ans += rec(nx, ny, level + 1);
            visited[nx][ny] = 0;
        }
    }
    else if (s[level] == '?') {
        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k], ny = j + dy[k];
            if (isvalid(nx, ny) && !visited[nx][ny]) {
                visited[nx][ny] = 1;
                ans += rec(nx, ny, level + 1);
                visited[nx][ny] = 0;
            }
        }
    }
    
    return ans;
}

void solve() {
    cin >> s;
    memset(visited, 0, sizeof(visited));
    visited[0][0] = 1;
    cout << rec(0, 0, 0) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
