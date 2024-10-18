#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
vector<vector<int>> a, p;

void solve(){
    cin>>n>>m;
    a.assign(n+1, vector<int>(m+1));
    p.assign(n+1, vector<int>(m+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    //precomputation 
    //for each one ill know wheres the next 0 in the same row!
    for(int i=0;i<n;i++){
        int zeroidx = m;
        for(int j=m-1;j>=0;j--){
            if(a[i][j]==0)zeroidx = j;
            p[i][j] = zeroidx;
        }
    } 

    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int width = m;
            for(int k=i;k>=0;k--){
                width = min(width, (p[k][j]-1) - (j) + 1);
                ans = max(ans, width*(i-k+1));
            }
        }
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
