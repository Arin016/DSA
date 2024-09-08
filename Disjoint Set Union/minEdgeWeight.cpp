#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define endl '\n' 
#define int long long
const int M = 1e9+7;
using state = pair<int, int>;
#define IOS                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
 
#include<bits/stdc++.h>
using namespace std;
#define F first 
#define S second
using state = pair<int, int>;

//You are given a weighted tree of N nodes. D(u,v) is defined as the minimum weight of edge in the simple path from u to v.  
//Find the summation of D(u,v) for all 1≤u≤N, 1≤v≤N, where u<v.
  

//2d = node--> i*m+j
struct DSU{
    int n;
    vector<int> leader, sizes;
    //t.c = O((n))
    DSU(int _n){
        n = _n;
        leader.resize(n+1);
        sizes.resize(n+1);
        for(int i=0;i<n+1;i++){
            leader[i] = i;
            sizes[i] = 1;
        }
    } 

    int getleader(int node){
        return leader[node] = (leader[node]==node) ? node : getleader(leader[node]);
    }
    //t.c = O(alpha(n))

    void unite(int x, int y){
        int leader_x = getleader(x);
        int leader_y = getleader(y);
        
        if(leader_x == leader_y)return ;

        if(sizes[leader_x]<sizes[leader_y])swap(leader_x, leader_y);

        leader[leader_y] = leader_x;
        sizes[leader_x]+=sizes[leader_y];
        return ;
    }

    //number of components = no of instances where x == getleader[x]
    //t.c = O(1)
};

int n;
vector<pair<int, state>> g;


void solve() {
    cin>>n;
    DSU dsu(n);
    int u, v, w;
    for(int i=0;i<n-1;i++){
        cin>>u>>v>>w;
        g.push_back({w, {u, v}});
    }
    sort(g.begin(), g.end());
    reverse(g.begin(), g.end());
    int ans = 0;
    for(auto x:g){
        int w = x.F;
        int u = x.S.F;
        int v = x.S.S;
        ans+=(w)*(dsu.sizes[dsu.getleader(u)]*dsu.sizes[dsu.getleader(v)]);
        dsu.unite(u, v);
    }
    cout<<ans<<endl;
}


signed main(){
	IOS
	int t=1;
	cin>>t;
	while(t--){
	    g.clear();
		solve();
	}
	
}