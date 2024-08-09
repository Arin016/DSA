#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int> towers; //maintain the top of each tower
    towers.push_back(a[0]);
    for(int i=1;i<n;i++){
        if(a[i]>=towers.back())towers.push_back(a[i]); //make new tower
        else{ //update the top
            auto it = upper_bound(towers.begin(), towers.end(), a[i]) - towers.begin(); 
            //first ele > a[i] so that i can place in that tower
            towers[it] = a[i];
        }
    }
    cout<<towers.size()<<endl;
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
