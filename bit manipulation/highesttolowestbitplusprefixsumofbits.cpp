#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        int p[n][30] = {0};
        for(int i=0;i<n;i++){
            for(int j=0;j<30;j++){
                p[i][j] = ((a[i]>>j)&1);
            }
        }
        for(int i=0;i<30;i++){
            for(int j=1;j<n;j++){
                p[j][i]+=p[j-1][i];
            }
        }
        int q;
        cin>>q;
        while(q--){
            int l, r;
            cin>>l>>r;
            int x1=0, x2=0, x3=0;
            for(int i=0;i<30;i++){
                int co = (l-1>=0)?p[r][i]-p[l-1][i]:p[r][i];
                int cz = (r-l+1)-co;
                if(co<cz){
                    x1+=(1LL<<i);
                }
                if(co!=(r-l+1))x2+=(1LL<<i);
                if(co>0)x3+=(1LL<<i);
            }
            cout<<x1+x2+x3<<endl;
        }
    }
}