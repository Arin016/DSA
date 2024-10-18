#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
#define endl "\n"

// |
// |____
// |

// |
// |
// |

int n;
vector<vector<int>> dp;
int rec(int level, int line){
    //pruning
    //base case
    if(level==1){
        return 1;
    }
    //cache check
    if(dp[level][line]!=-1)return dp[level][line];
    //compute
    int ans = 0;
    if(line==0){
        (ans+=rec(level-1, 1)%mod+(2*rec(level-1, 0)%mod)%mod)%=mod;
    }
    else if(line==1){
        (ans+=(4*rec(level-1, 1)%mod)%mod+rec(level-1, 0)%mod)%=mod;
    }
    //save and return
    return dp[level][line] = ans;
}
void solve(){
    cin>>n;
    cout<<(rec(n, 0)+rec(n, 1))%mod<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    dp.assign(1e6+100, vector<int>(2, -1));
    while(t--){
        solve();
    }
}
