#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second

//bit expressions are sum independent on each bit
//a&b + a|b = a+b



void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int ans = 0;
    for(int i=0;i<=30;i++){
        int co = 0, cz = 0;
        for(int j=0;j<n;j++){
            if((a[j]>>i)&1){
                co++;
            }
            else cz++;
        }
        ans+=(co*cz)*(1<<i);
    }
    cout<<ans<<endl;
}

signed main(){
    solve();
}