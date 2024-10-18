#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, k;
vector<int> a;


struct monotoneDeque{
    deque<int> dq;

    void insert(int x){
        while(!dq.empty() and dq.back()>x){
            dq.pop_back();
        }
        dq.push_back(x);
    }

    void erase(int x){
        if(dq.front()==x)dq.pop_front();
    }

    int getmin(){
        return dq.front();
    }
};

// int rec(int level){
//     //pruning
//     if(level>=n)return 0;
//     //base case
//     if(level==n-1)return a[level];
//     //cache check
//     //compute
//     int ans = 1e18;
//     for(int i=level+1;i<=min(n-1, level+k);i++){
//         ans = min(ans, a[level]+rec(i));
//     }
//     //save and return
//     return ans;
// }


vector<int> dp; 
monotoneDeque mD;
//j-k se j+k ke liye niche wale mein row mein har index ke liye apne piche 2k-1 length ka max ke liye deque likh
//aur jab compute karna ho kisi i index wale ke liye toh niche wale row mein jaakar i+k se value lena hai


void solve(){
    cin>>n>>k;
    a.resize(n+1);
    dp.assign(n+1, -1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int level=n-1;level>=0;level--){
        //pruning
        //base case
        if(level==n-1){
            dp[level] = a[level];
            continue;
        }
        //compute
        mD.insert(dp[level+1]);
        if(level+k+1<n)mD.erase(dp[level+k+1]);
        int ans = a[level]+mD.getmin();
        dp[level] = ans;
    }
    cout<<dp[0]<<endl;
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
