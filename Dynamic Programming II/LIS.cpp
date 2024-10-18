#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
vector<int> a;

int rec(int level, int pi){
    //pruning
    //base case
    if(level==n)return 0;
    //cache check
    //compute
    int ans = -1e9;
    //take it
    if(a[level]>a[pi] || pi==-1){
        ans = max(ans, 1+rec(level+1, level));
    }
    //skip it
    ans = max(ans, rec(level+1, pi));
    //save and return
    return ans;
}

void printsol(int level, int pi){
    //pruning
    //base case
    if(level==n)return;
    //cache check
    //compute
    int ans = rec(level, pi);
    //catch the right transition
    if(ans==1+rec(level+1, level)){
        cout<<a[level]<<" ";
        printsol(level+1, level);
    }
    else if(ans==rec(level+1, pi)){
        printsol(level+1, pi);
    }
}
void solve(){
    cin>>n;
    a.resize(n+1);
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<rec(0, -1)<<endl;
    printsol(0, -1);
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
