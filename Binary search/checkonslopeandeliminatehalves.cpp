#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

long double f(int x){

}

void solve(){
   long double lo,hi,ans,eps;
   lo = 0;
   hi = 1e18;
   eps = 1e-12;
   for(int i=0;i<60;i++){
    long double mid = (lo+hi)/2;
     if(f(mid)<f(mid+eps)){
        lo = mid;
     }else{
        hi = mid;
     }
   }

   ans = (lo+hi)/2;
    
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}