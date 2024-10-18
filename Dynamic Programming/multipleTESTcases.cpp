#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, T;
vector<int> a;
vector<vector<int>> dp;
//design state in a nice way so that you could use it across multiple test cases
//so that we could use the same dp cache across multiple queries 
// int rec(int level, int ssum){ //no of subsets in level....n-1 with ssum as its subsetsum!
//     //pruning
//     if(ssum<0)return 0;
//     //base case
//     if(level==n){
//         return ssum==0;
//     }
//     //cache check
//     if(dp[level][ssum]!=-1)return dp[level][ssum];
//     //compute
//     int ans = 0;
//     //take it
//     ans+=rec(level+1, ssum-a[level]);
//     //dont take it
//     ans+=rec(level+1, ssum);
//     //save and return
//     return dp[level][ssum] = ans;
// }
int rec(int level, int ssum){ //if a subset in level....n-1 with ssum as its subsetsum!
    //pruning
    if(ssum<0)return 0;
    //base case
    if(level==n){
        return ssum==0;
    }
    //cache check
    if(dp[level][ssum]!=-1)return dp[level][ssum];
    //compute
    int ans = 0;
    //take it
    ans|=rec(level+1, ssum-a[level]);
    //dont take it
    ans|=rec(level+1, ssum);
    //save and return
    return dp[level][ssum] = ans;
}

vector<int> indices;
void printsol(int level, int ssum){
    //pruning
    if(ssum<0)return;
    //base case
    if(level==n){
        return;
    }
    //compute
    int ans = rec(level, ssum);
    //catching the right transition!
    if(rec(level+1, ssum-a[level])==ans){
        indices.push_back(level);
        printsol(level+1, ssum-a[level]);
        return;
    }
    else if(rec(level+1, ssum)==ans){
        printsol(level+1, ssum);
        return;
    }
}

void solve(){
    cin>>n>>T;
    a.resize(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dp.assign(1e2+200, vector<int>(1e4+400, -1));
    cout<<rec(0, T)<<endl;
    printsol(0, T);
    for(auto x:indices){
        cout<<a[x]<<" ";
    }
    cout<<endl;
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
