#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, x, y, z;
vector<int> a;
vector<vector<int>> done;
vector<vector<vector<int>>> dp;

int rec(int l, int r, int xx){
    //min cost to merge l....r and get to a value  = xx
    //pruning
    //base case
    if(l==r){
        if(a[l]==xx)return 0;
        else return 1e18;
    }
    //cache check
    if(done[l][r]==1)return dp[l][r][xx];
    //compute
    for(int i=0;i<50;i++)dp[l][r][xx] = 1e18;
    for(int mid=l;mid<r;mid++){
        for(int fs=0;fs<50;fs++){
            for(int ls=0;ls<50;ls++){
                dp[l][r][(fs*x+ls*y+z)%50] = min(dp[l][r][(fs*x+ls*y+z)%50], fs*ls+rec(l, mid, fs)+rec(mid+1, r, ls));
            }
        }
    }
    done[l][r] = 1;
    //save and return
    return dp[l][r][xx];
}
void solve(){
    cin>>n>>x>>y>>z;
    a.resize(n+1);
    done.assign(n+1, vector<int>(n+1, 0));
    dp.assign(n+1, vector<vector<int>>(n+1, vector<int>(50, 1e18)));
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans = 1e18;
    for(int xx=0;xx<50;xx++){
        ans = min(ans, rec(0, n-1, xx));
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
