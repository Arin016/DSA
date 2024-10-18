#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define F first
#define S second 
#define int long long
const int mod = 1e9+7;
const int INF = 1e9;
using state = pair<int, int>;

int n;
int arr[100100][3];
int dp[100100][3];

int rec(int i, int p){
    //pruning
    //base case
    if(i==n)return 0;
    //cache check
    if(dp[i][p]!=-1)return dp[i][p];
    //compute
    int ans = -1e18;
    if(p==0){
        ans = max({ans, rec(i+1, 1)+arr[i][1], rec(i+1, 2)+arr[i][2]});
    }
    else if(p==1){
        ans = max({ans, rec(i+1, 0)+arr[i][0], rec(i+1, 2)+arr[i][2]});
    }
    else if(p==2){
        ans = max({ans, rec(i+1, 1)+arr[i][1], rec(i+1, 0)+arr[i][0]});
    }
    //save and return
    return dp[i][p] = ans;
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            dp[i][j]=-1;
        }
    }
    for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    cout<<max({rec(0, 0), rec(0, 1), rec(0, 2)})<<endl;
}

signed main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    int _t=1;
    //cin>>_t;
    while(_t--){
        solve();
    }
}