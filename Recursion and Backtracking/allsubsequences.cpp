#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
vector<int> arr;
vector<int> sol;
vector<vector<int>> allsol;

void rec(int level){
    if(level==n){
        allsol.push_back(sol);
        for(auto x:sol){
            cout<<x<<" ";
        }
        cout<<endl;
        return;
    }
    rec(level+1);
    sol.push_back(arr[level]);
    rec(level+1);
    sol.pop_back();
}

void solve(){
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    rec(0);
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
