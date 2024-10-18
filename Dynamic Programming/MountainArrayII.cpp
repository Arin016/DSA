#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
vector<int> a;

void solve(){
    cin>>n;
    a.resize(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    //LIS in 0....i
    vector<int> dp1(n);
    vector<int> lis;
    for(int i=0;i<n;i++){
        if(lis.empty() || lis.back()<a[i]){
            lis.push_back(a[i]);
        }
        else{
            auto it = lower_bound(lis.begin(), lis.end(), a[i]);
            *it = a[i];
        }
        dp1[i] = lis.size();
    }
    //LDS in i....n
    vector<int> dp2(n);
    vector<int> lds;
    for(int i=n-1;i>=0;i--){
        if(lds.empty() || lds.back()<a[i]){
            lds.push_back(a[i]);
        }
        else{
            auto it = lower_bound(lds.begin(), lds.end(), a[i]);
            *it = a[i];
        }
        dp2[i] = lds.size();
    }

    int maxi = 0;
    for(int pivot=0;pivot<n;pivot++){
        if(dp2[pivot]>1 and dp1[pivot]>1)maxi = max(maxi, dp1[pivot]+dp2[pivot]-1);
    }
    if(maxi<3){
        cout<<-1<<endl;
    }
    else cout<<n-maxi<<endl;
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
