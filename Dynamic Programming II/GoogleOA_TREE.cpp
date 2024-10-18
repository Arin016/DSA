#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

bool isprime(int x){
    for(int i=2;i*i<=x+1;i++){
        if(x%i==0)return false;
    }
    return true;
}

int n, m;
vector<vector<int>> g;
vector<int> primes;
vector<vector<int>> dp;

//dp[node][i] = number of ways you could fill nodes ka subtree given that node is colored with color i!
void dfs(int node, int par){
    //assuming its a leaf node
    for(int i=0;i<25;i++){
        dp[node][i] = 1;
    }

    for(auto x:g[node]){
        if(x!=par){
            dfs(x, node);
            for(int i=0;i<25;i++){
                int ways = 0;
                for(int j=0;j<25;j++){
                    if(isprime(primes[i]+primes[j])==0){
                        ways+=dp[x][j];
                    }
                }
                dp[node][i] *= ways;
            }
        }
    }
}

void solve(){
    cin>>n;
    m = n-1;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=2;i<=100;i++){
        if(isprime(i))primes.push_back(i);
    }
    dp.assign(n+1, vector<int>(27, -1));
    dfs(1, -1);
    int ans = 0;
    for(int i=0;i<25;i++){
        ans+=dp[1][i];
    }
    cout<<ans<<endl;
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
