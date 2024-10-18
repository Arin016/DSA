#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

/*
question 1
you are given an array A of size N
M and L also given 
L is the atmost sub array size that you can take
M you can perform Atmost M times
in one operation you can take a subarray and subtract 1 form it
task is to fin minimum of maximum from the resultant array

testcase:
4 4 3 4 1
L=3 M = 4 ans = 2

6
4 3 1 6 4 6
L = 2 , M = 2
ans = 5
*/

int n, l, m;
vector<int> a;
//00000001111111
bool check(int mid){
    int temp = m;
    int cnt = 0;
    vector<int> p(n, 0);
    for(int i=0;i<n;i++){
            //update cnt first of all!
            cnt+=p[i];
            int diff = a[i]+cnt-mid;
            if(diff>0){
                temp-=(diff); //kill those many operations
                cnt+=-1*(diff); //update cnt
                p[i]+=-1*(diff); //mark in p array
                if(i+l<n)p[i+l]-=-1*(diff); //anti mark in p array
            }
    }
    return temp>=0;
}

void solve(){
    cin>>n>>l>>m;
    a.resize(n+1);
    int maxi = -1e18;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxi = max(maxi, a[i]);
    }
    int lo = m-maxi, hi = maxi, ans = -1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(check(mid)){
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    cout<<ans<<endl;
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
