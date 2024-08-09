#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin>>n>>x;
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        int ans = 0;
        for(int i=30;i>=0;i--){
            vector<int> temp;
            for(auto x:a){
                if((x>>i)&1LL)temp.push_back(x);
            }
            if(temp.size()>=x){
                a = temp;
                ans+=(1LL<<i);
            }
        }
        cout<<ans<<endl;
    }
}