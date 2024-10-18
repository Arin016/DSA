#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

// look at what the problem is asking for try out some examples manually and decipher if something is hidden 
//that is of the standard form itself, most of the times this itself is the case that there is a very
//minor tweak in standard FORMS!


//we can decipher making subarrys into picking the ""subsequence ""of each of 
//the subarrays ka end point 



//SUBARRAYS!
//either start new or continue;
//use for loops and make all possible ends and go furthur




//revise DECODE problem from codeforces, contribution tecnique!



int n, k;
vector<int> a;

int rec(int i, int kk){
    //pruning
    if(kk<0)return 1e18;
    //base case
    if(i==n){
        if(kk==0)return 0;
        else return 1e18;
    }
    //cache check
    //compute
    int ans = 1e18;
    int mini = a[i];
    for(int j=i;j<n;j++){
        mini = min(mini, a[j]);
        ans = min(ans, mini+rec(j+1, kk-1));
    }
    //save and return
    return ans;
}
void printsol(int i, int kk){
    // pruning
    if(kk < 0) return;
    // base case
    if(i == n){
        if(kk == 0) return;
        else return;
    }
    
    // compute solution to match with rec()
    int ans = rec(i, kk);
    int mini = a[i];
    for(int j=i;j<n;j++){
        mini = min(mini, a[j]);
        if(ans==mini+rec(j+1, kk-1)){
            cout << mini << " ";
            printsol(j + 1, kk - 1);
            return; // yeh return marana zaruri hai
        }
    }
}


void solve(){
    cin>>n>>k;
    a.resize(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<rec(0, k)<<endl;
    printsol(0, k);
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
