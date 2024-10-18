#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, k;
vector<int> a;

//you couldve made a O(n^3) formulation too!
//dp(level, kk) and transitions being skip or use a for loop and pick a subarray!

int rec(int level, int kk, bool f){ 
    //maximum sums of subarray if we are supposed to compute in level....n-1 with kk more subarrays to pick
    //and the current subarray being open or not given by f!
    //pruning
    if(kk < 0) return -1e18;  // prevent invalid subarray count
    //base case
    if(level==n){
        if(kk==0)return 0;
        return -1e18;
    }
    //cache check
    //compute
    int ans = -1e18;
    if(f==0){
        ans = max(ans, rec(level+1, kk, 0)); //skip this!
        ans = max(ans, a[level]+rec(level+1, kk-1, 1)); //start new subarray here!
    }
    else if(f==1){
        ans = max(ans, a[level]+rec(level+1, kk, 1)); //continue into previous subarray!
        ans = max(ans, a[level]+rec(level+1, kk-1, 1));//end here and start new one!
        ans = max(ans, rec(level+1, kk, 0)); //end here!
    }
    //save and return
    return ans;
}

void solve(){
    cin>>n>>k;
    a.resize(n+1);  // resizing the array size to n+1 to avoid overflow
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<rec(0, k, 0)<<endl;  // Correcting k value in rec function call
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
