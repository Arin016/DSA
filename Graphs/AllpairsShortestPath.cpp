#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    int n;
    cin>>n;
    int dis[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>dis[i][j];
        }
    }
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //the order in which you are picking the kk nodes to relax is important!!
    //watch video editorial if req again its worth it!
    vector<int> ans;
    for(int kk=n-1;kk>=0;kk--){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j] = min(dis[i][j], dis[i][a[kk]]+dis[a[kk]][j]);
            }
        }
        int sum = 0;
        for(int i=kk;i<n;i++){
            for(int j=kk;j<n;j++){
                sum+=dis[a[i]][a[j]];
            }
        }
        ans.push_back(sum);
    }
    for(int i=n-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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
