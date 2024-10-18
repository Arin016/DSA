#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
vector<int> a;
vector<vector<int>> dp;

int rec(int l, int r){ //min no of steps required to decompose this range [l....r]
    //isko aise hi likhna hai, 
    //think from the perspective of the aL how is this element going to get solved/move??
    //pruning
    //base case
    if(l>r)return 0;
    if(l==r)return 1;
    //cache check
    if(dp[l][r]!=-1)return dp[l][r];
    //compute
    int ans = 1e18;
    ans = min(ans, 1+rec(l+1, r)); //usko akele hi ko ek palindrome bana diya!
    if(a[l]==a[l+1]){ //agar pehle ke do same ho rhe toh undono ko mila ke hata de!
        ans = min(ans, 1+rec(l+2, r));
    }
    for(int k=l+2;k<=r;k++){
        if(a[l]==a[k]){
            ans = min(ans, rec(l+1, k-1)+rec(k+1, r)); //kahin aur mile "k" index par toh
            //l ..... k ....... r
            //jitna cost mein l+1....k-1 decompose ho rha utne mein hi free mein l wala aur k wala
            //ho jayega aur phir k+1....r ka alag se calculate kar!
        }
    }
    //save and return
    return dp[l][r] = ans;
}

void solve(){
    cin>>n;
    a.resize(n+1);
    dp.assign(n+1, vector<int>(n+1, -1));
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<rec(0, n-1)<<endl;
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
