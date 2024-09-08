#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
//Q-->
//each node has some value, maximise the sum of value taken 
//such that no 2 adjacent nodes should be selected

int n;
vector<vector<int>> g;
int arr[100100];
int dp[100100][2];
int ans = 0;


// **State:**

// - `dp(node, 0) =` Maximum value set in subtree of node such that node is **NOT** taken.

// - `dp(node, 1) =` Maximum value set in subtree of node such that node is taken.

// **Transition:**

// - `dp(node, 0) = ∑ max(dp(child, 0), dp(child, 1))` for each child.

// - `dp(node, 1) = A[node] + ∑ dp(child, 0)` for each child.

// **Final answer:**

// - `MAX(dp(root, 0), dp(root, 1))`


//dp(node, takethis/donttakethis)
void indfs(int node, int par){ 
    //fill these as if leaf node
    dp[node][1] = arr[node];
    dp[node][0] = 0;
    for(auto x:g[node]){
        if(x!=par){
            indfs(x, node);
            dp[node][1] += dp[x][0]; //you cant take child if you take node
            dp[node][0] += max(dp[x][0], dp[x][1]); //you may/maynot take child if node isnt taken
        }
    }
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    g.clear();
    g.resize(n+1);
    ans = 0;

    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    memset(dp, -1, sizeof(dp));
    indfs(1, 0);
    cout<<max(dp[1][0], dp[1][1])<<endl;
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
