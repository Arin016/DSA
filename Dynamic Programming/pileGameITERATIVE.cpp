#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;



int rec(int i, int j){
    //pruning
    //base case
    if(i==0 and j==0)return 0; //its a losing state!
    //cache check
    //compute
    int ans = 1; //assume its a winnnig state!
    //either pick from i
    for(int k=1;k<=i;k++){
        ans&=rec(i-k, j);
    }
    //either pick it all from j
    for(int k=1;k<=j;k++){
        ans&=rec(i, j-k);
    }
    //pick same length from both!
    for(int k=1;k<=min(i, j);k++){
        ans&=rec(i-k, j-k);
    }
    ans^=1; 
    //save and return
    return ans;
}

void solve(){
    int a, b;
    int dp[a+1][b+1];
    //order of computation of loops
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            //pruning
            //base case
            if(i==0 and j==0){
                dp[i][j] = 0; //its a losing state!
                continue;
            }
            //cache check
            //compute
            int ans = 1; //assume its a winnnig state!
            //either pick from i
            for(int k=1;k<=i;k++){
                ans&=dp[i-k][j];
            }
            //either pick it all from j
            for(int k=1;k<=j;k++){
                ans&=dp[i][j-k];
            }
            //pick same length from both!
            for(int k=1;k<=min(i, j);k++){
                ans&=dp[i-k][j-k];
            }
            ans^=1; 
            //save and return
            dp[i][j] = ans;
            }
    }
    cout<<dp[a][b]<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
