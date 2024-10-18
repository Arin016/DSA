#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int> lis;
    vector<int> insertedat(n);
    for(int i=0;i<n;i++){
        if(lis.empty() or lis.back()<a[i]){
            lis.push_back(a[i]);
            insertedat[i] = lis.size();
        }
        else{
            auto it = lower_bound(lis.begin(), lis.end(), a[i]);
            *it = a[i];
            insertedat[i] = it-lis.begin()+1;
        }
    }
    cout<<lis.size()<<endl;
    for(int i=0;i<n;i++){
        cout<<insertedat[i]<<" ";
    }
    cout<<endl;
    vector<int> ans;
    int currlen = lis.size();
    for(int i=n-1;i>=0;i--){
        if(insertedat[i]==currlen){
            ans.push_back(a[i]);
            currlen--;
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto x:ans){
        cout<<x<<" ";
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
