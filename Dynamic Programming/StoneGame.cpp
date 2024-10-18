#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, k;
int mini;
vector<int> a;
vector<int> dp;

int rec(int x){
    // pruning
    // base case
    if(x < mini) return 0; // having fewer than mini stones is a losing state
    // cache check
    if(dp[x] != -1) return dp[x];
    // compute
    int ans = 1; // assuming it's a losing state
    for(int i = 0; i < n; i++){
        if(x - a[i] >= 0){
            ans&=rec(x-a[i]);
        }
    }
    //if ans is still 1 that means all of the transitions were winning state thus our asumption of
    //current state being winning is wrong!
    ans^=1;
    // save and return
    return dp[x] = ans;
}

void solve(){
    cin >> n >> k;
    a.resize(n);
    dp.assign(k + 1, -1);
    mini = 1e18;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mini = min(mini, a[i]);
    }
    // Taro starts, Jiro plays second
    if(rec(k) == 1){
        cout << "First" << endl;
    }
    else {
        cout << "Second" << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
