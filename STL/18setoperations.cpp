#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    int n, m;
    cin>>n>>m;
    int a[n], b[m];
    set<int> st1, st2;
    for(int i=0;i<n;i++)cin>>a[i], st1.insert(a[i]);
    for(int i=0;i<m;i++)cin>>b[i], st2.insert(b[i]);
    set<int> un;
    for(int i=0;i<n;i++)un.insert(a[i]);
    for(int i=0;i<m;i++)un.insert(b[i]);
    set<int> in;
    for(int i=0;i<n;i++){
        if(st1.count(a[i]) and st2.count(a[i]))in.insert(a[i]);
    }
    for(int i=0;i<m;i++){
        if(st1.count(b[i]) and st2.count(b[i]))in.insert(b[i]);
    }
    set<int> diff;
    for(int i=0;i<n;i++){
        if(!st2.count(a[i]))diff.insert(a[i]);
    }
    //union
    for(auto it = un.begin();it!=un.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    //inter
    for(auto it = in.begin();it!=in.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    //diff
    for(auto it = diff.begin();it!=diff.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
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
