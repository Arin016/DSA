#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define MP make_pair
#define INF 1e18
int mod = 1e9+7;

typedef pair<int, int> pii;
typedef pair<long, long> pll;
using state = pair<int, int>;

int dircost[] = {1, 2, 3, 4};  // Cost to go in direction U, R, D, L respectively
char dirchar[] = {'U', 'R', 'D', 'L'};
int dx[] = {-1, 0, +1, 0};
int dy[] = {0, +1, 0, -1};

int n, m;
vector<string> arr;
vector<vector<int>> dis;
vector<vector<int>> vis;
vector<vector<state>> parent;
vector<vector<int>> num_path;

bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && arr[x][y] != 'W';
}

bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && arr[x][y] == '.';
}

vector<state> neighbours(state cur) {
    vector<state> ans;
    for (int i = 0; i < 4; i++) {
        if (is_valid(cur.F + dx[i], cur.S + dy[i])) {
            ans.push_back({cur.F + dx[i], cur.S + dy[i]});
        }
    }
    return ans;
}

void process(vector<state> pos[]) {
    for (int dir = 0; dir < 4; dir++) {
        for (auto v : pos[dir]) {
            int x = v.F + dx[dir];
            int y = v.S + dy[dir];
            while (check(x, y) && arr[x][y] != dirchar[dir]) {
                if (arr[x][y] == '.') {
                    arr[x][y] = 'B';
                }
                x += dx[dir];
                y += dy[dir];
            }
        }
        for (auto v : pos[dir]) {
            int x = v.F;
            int y = v.S;
            arr[x][y] = 'B';
        }
    }
}

void bfs(state st) {
    vis = vector<vector<int>>(n, vector<int>(m, 0));
    dis = vector<vector<int>>(n, vector<int>(m, INF));
    num_path = vector<vector<int>>(n, vector<int>(m, 0));
    parent = vector<vector<state>>(n, vector<state>(m, MP(-1, -1)));

    priority_queue<pair<int, state>> pq;
    dis[st.F][st.S] = 0;
    num_path[st.F][st.S] = 1;
    pq.push({0, st});

    while (!pq.empty()) {
        pair<int, state> xx = pq.top();
        pq.pop();
        state cur = xx.S;

        if (vis[cur.F][cur.S]) {
            continue;
        }
        vis[cur.F][cur.S] = 1;

        for (int dir = 0; dir < 4; dir++) {
            int x = cur.F + dx[dir];
            int y = cur.S + dy[dir];
            if (check(x, y) && arr[x][y] != 'B') {
                if (dis[x][y] > dis[cur.F][cur.S] + dircost[dir]) {
                    parent[x][y] = cur;
                    dis[x][y] = dis[cur.F][cur.S] + dircost[dir];
                    num_path[x][y] = num_path[cur.F][cur.S];
                    pq.push({-dis[x][y], {x, y}});
                } else if (dis[x][y] == dis[cur.F][cur.S] + dircost[dir]) {
                    num_path[x][y] += num_path[cur.F][cur.S];
                }
            }
        }
    }
}

void updatepath(state en) {
    state not_possible = {-1, -1};
    while (en != not_possible) {
        if (arr[en.F][en.S] == '.') {
            arr[en.F][en.S] = 'P';
        }
        en = parent[en.F][en.S];
    }
}

void solve() {
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    state st, en;
    vector<state> pos[4];  // U=0, R=1, D=2, L=3
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'S') {
                st = {i, j};
            } else if (arr[i][j] == 'E') {
                en = {i, j};
            } else if (arr[i][j] == 'U') {
                pos[0].push_back({i, j});
            } else if (arr[i][j] == 'R') {
                pos[1].push_back({i, j});
            } else if (arr[i][j] == 'D') {
                pos[2].push_back({i, j});
            } else if (arr[i][j] == 'L') {
                pos[3].push_back({i, j});
            }
        }
    }

    process(pos);
    bfs(st);
    updatepath(en);
    cout << dis[en.F][en.S] << endl;
    cout << num_path[en.F][en.S] << endl;

    for (auto v : arr) {
        cout << v << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}
