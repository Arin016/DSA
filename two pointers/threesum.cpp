#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    int n, t;
    cin>>n>>t;
    int arr[n];
    map<int, int> f;
    for(int i=0;i<n;i++)cin>>arr[i], f[arr[i]]++;
    vector<int> a;
    for(auto x:f)a.push_back(x.first);
    int mini = 1e18;
    for(int j=1;j<a.size()-1;j++){
        int i=0, k=a.size()-1;
        while(i<j and k>j){
            int curval = a[i]+a[k]+a[j];
            if(curval-t>0){
                k--;
            }
            else if(0>curval-t){
                i++;
            }
            else{
                cout<<0<<endl;
                return;
                i++;
                k--;
            }
            mini = min(mini, abs(t-curval));
        }
    }
    cout<<mini<<endl;
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
