#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

/*
There is a list of n numbers and two players who move alternately. 
On each move, a player removes either the first or last number from the list, 
and their score increases by that number. Both players try to maximize their scores.
What is the maximum possible score for the first player when both players play optimally?
*/

int n;
vector<int> a, p;
vector<vector<int>> dp, done;
int q(int l, int r){
    return p[r]-p[l-1];
}

int rec(int l, int r){ 
    //maximum score obtained by the player who is playing on this current turn
    //with l....r as the current range!
    //pruning
    if(l>r)return 0;
    //base case
    //cache check
    if(done[l][r])return dp[l][r];
    //compute
    int ans = -1e18;
    ans = max(ans, q(l, r)-rec(l+1, r));
    ans = max(ans, q(l, r)-rec(l, r-1));
    //save and return 
    done[l][r] = 1;
    return dp[l][r] = ans;
}

vector<int> picks;
void printsol(int l, int r){
    //pruning
    if(l>r)return;
    //base case
    //cache check
    //compute
    int ans = rec(l, r);
    if(ans==q(l, r)-rec(l+1, r)){
        picks.push_back(a[l]);
        printsol(l+1, r);
        return;
    }
    if(ans==q(l, r)-rec(l, r-1)){
        picks.push_back(a[r]);
        printsol(l, r-1);
        return;
    }
}

void solve(){
    cin>>n;
    a.assign(n+2, 0);
    p.assign(n+2, 0);
    dp.assign(n+1, vector<int>(n+1, 0));
    done.assign(n+1, vector<int>(n+1, 0));
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]+a[i];
    }
    // // cout<<rec(1, n)<<endl;
    // printsol(1, n);
    // //alice starts picking so every alteranate number printed was picked by alice!
    // int diff = 0;
    // for(int i=0;i<picks.size();i++){
    //     if(i&1)diff-=picks[i];
    //     else diff+=picks[i];
    // }
    // cout<<(diff)<<endl;
    //direct bhi likh sakta BKL
    cout<<rec(1, n)-(p[n]-rec(1, n))<<endl;
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
