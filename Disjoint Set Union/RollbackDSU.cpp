#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
#define F first 
#define S second

struct RBdsu{
    multiset<int> cmpsz;
    vector<int> par, size;
    vector<pair<int, int>> st; //maintains the change delta!! 
    //this idea can be extended furtur of maintainnig deltas

    void init(int n){
        par.resize(n+1);
        size.resize(n+1);
        st.clear();
        cmpsz.clear();
        for(int i=1;i<=n;i++){
            par[i] = i;
            size[i] = 1;
            cmpsz.insert(1);
        }
    }

    int find(int x){
        //no path compreession in rollback!!
        if(x==par[x])return x;
        else return find(par[x]);
    }

    bool merge(int x, int y){
        int xL = find(x);
        int yL = find(y);
        if(xL==yL)return 0;
        if(size[xL]<size[yL])swap(xL, yL); //size[xL] > size[yL]

        cmpsz.erase(cmpsz.find(size[xL]));
        cmpsz.erase(cmpsz.find(size[yL]));
        par[yL] = xL;
        st.push_back({yL, xL}); //{isko chnage kiya, itne se}
        size[xL]+=size[yL];
        cmpsz.insert(size[xL]);
        return 1;
    }

    void rollback(){
        while(!st.empty()){
            auto cur = st.back();
            st.pop_back();
            int initialpar = cur.first;
            int changepar = cur.second;
            cmpsz.erase(cmpsz.find(size[changepar]));
            par[initialpar] = initialpar;
            size[changepar]-=size[initialpar];
            cmpsz.insert(size[initialpar]);
            cmpsz.insert(size[changepar]);
        }
    }

    int getmax(){
        auto it = cmpsz.end();
        it--;
        return *it;
    }
};

int n, m;
vector<vector<int>> a, nodeno;
vector<pair<pair<int, int>, pair<int, int>>> edges; //((), ())
bool isvalid(int x, int y){
    if(x>=0 and x<n and y>=0 and y<m)return 1;
    return 0;
}

int dx[] = {1, 0};
int dy[] = {0, 1};

void solve(){
    cin >> n >> m;
    RBdsu dsu;
    dsu.init(n * m + 1);
    int cnt = 1;
    a = vector<vector<int>>(n+1,vector<int>(m+1,0));
    nodeno = vector<vector<int>>(n+1,vector<int>(m+1,0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            nodeno[i][j] = cnt++;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 2; k++) {
                int xx = i + dx[k];
                int yy = j + dy[k];
                if (isvalid(xx, yy)) {
                    int cc1 = a[i][j];
                    int cc2 = a[xx][yy];
                    if (cc1 > cc2) swap(cc1, cc2);
                    if (cc1 != cc2) {
                        edges.push_back({{cc1, cc2}, {nodeno[i][j], nodeno[xx][yy]}});
                    } else {
                        dsu.merge(nodeno[i][j], nodeno[xx][yy]);
                    } 
                }
            }
        }
    }

    dsu.st.clear();
    sort(edges.begin(), edges.end());
    int ans = dsu.getmax();

    for (int i = 0; i < edges.size(); i++) {
        int j = i;
        while (j < edges.size() && edges[i].F == edges[j].F) {
            dsu.merge(edges[j].S.F, edges[j].S.S);
            j++;
        }
        ans = max(ans, dsu.getmax());
        dsu.rollback();
        i = j - 1;
    }

    cout << ans << endl;
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
