//using Binary search on ans
#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


int n, k;
int a[1001001];
int p[1001001];


// bool check(int mid){
//     int l = 0, r = mid-1;
//     while(r<n){
//         if((mid-(p[r]-p[l-1]))<=k)return 1;
//         l++, r++;
//     }
//     return 0;
// }


bool check(int mid, int start){
    int ones = (start-1>=0)?p[mid]-p[start-1]:p[mid];
    int len = mid-start+1;
    int zeroes = len-ones;
    return k>=zeroes;
}

void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        p[i] = a[i];
        if(i)p[i]+=p[i-1];
    }
    //binary search on ans
    // int lo = 1, hi = n, ans = 1;
    // while(lo<=hi){
    //     int mid = lo+(hi-lo)/2;
    //     if(check(mid)){
    //         ans = mid;
    //         lo = mid+1;
    //     }
    //     else hi = mid-1;
    // }
    // cout<<ans<<endl;
      
    //binary search on every start
    int fans = 0;
    for(int i=0;i<n;i++){
        int start = i;
        int lo = i, hi = n-1, ans = i-1; //look carefully ans is set to be start-1 because in the case where k is 0 the number of subarrays must be 0 ((start-1)-start+1) 
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(check(mid, start)){
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        fans = max(ans, fans);
        //fans+=(ans-start+1); //to count the number of subarrays which has <=k zeroes
    }
    cout<<fans<<endl;
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
