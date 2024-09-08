#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


struct wdsu{
    int cmp;
    vector<pair<int, int>> par;
    vector<int> size;

    void init(int n){
        cmp = n;
        par.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            par[i] = {i, 0};
            size[i] = 1;
        }
    }
    //*********##########********//
    //(leader, cost to reach leader)
    pair<int, int> find(int x){
        if(x==par[x].first){
            return par[x];
        }
        else{
            auto temp = find(par[x].first);
            par[x] = {temp.first, temp.second+par[x].second};
            return par[x];
        }
    }
    //YT video DSU part 2!
    //x--(c)-->y
    //x<--(-c)--y
    bool merge(int x, int y, int c){
        auto xL = find(x);
        auto yL = find(y);
        if(xL.first==yL.first)return 0;
        int X = par[x].second;
        int Y = par[y].second;
        if(size[xL.first]>size[yL.first]){
            size[xL.first]+=size[yL.first];
            //c+Y+newedge = X
            int newedge = X-Y-c;
            par[yL.first].second+=newedge;
            par[yL.first].first = xL.first;
        }
        else{
            size[yL.first]+=size[xL.first];
            //c+Y+(-newedge) = X
            int newedge = -(X-Y-c);
            par[xL.first].second+=newedge;
            par[xL.first].first = yL.first;
        }
    }
};

void solve(){
    int n, q;
    cin>>n>>q;
    wdsu d;
    d.init(n);
    while(q--){
        int ch;
        cin>>ch;
        if(ch==0){
            int x, y, c;
            cin>>y>>x>>c;
            bool f = d.merge(x, y, c);
        }
        else{
            int x, y;
            cin>>y>>x;
            auto c1 = d.find(x), c2 = d.find(y);
            if(c1.first!=c2.first)cout<<'?'<<endl;
            else cout<<c1.second-c2.second<<endl;
        }
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
