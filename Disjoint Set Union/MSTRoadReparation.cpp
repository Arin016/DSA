#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;


using state = pair<int,int>;

int par[100100];
int size[100100];

int find(int x){
    return par[x] = (par[x]==x)?x:find(par[x]);
}

int unite(int x,int y){
    int rootx = find(x);
    int rooty = find(y);
    if(size[rootx]<size[rooty])swap(x,y);
    size[rootx] += size[rooty];
    par[rooty] = rootx;
}

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        par[i] = i;
        size[i] = 1;
    }
    vector<pair<int,state>> edgelist;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edgelist.push_back({c,{a,b}});
        //edgelist.push_back({c,{b,a}});
    }

    sort(edgelist.begin(),edgelist.end());
    
    int mst = 0;
    int cnt = 0;
    for(auto v:edgelist){
        int x = v.S.F;
        int y = v.S.S;
        if(find(x)!=find(y)){
            cnt ++;
            mst += v.F;
            unite(x,y); 
        }
    }
    //look at this CASE
    //if no of edges put are not equal to n-1 that means this isnt a tree hence Impossible!
    if(cnt != (n-1)){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        cout<<mst<<endl;
    }

        
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}