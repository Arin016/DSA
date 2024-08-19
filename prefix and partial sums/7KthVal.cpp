#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

void solve() {
    int n,m,q;
        cin>>n>>m>>q;
        int a[n+1]={0}; //given elements
        int o[n+1]={0}; //freq of each element
        for(int i=1;i<n+1;i++)cin>>a[i];
        while(m--){
            int l,r;
            cin>>l>>r;
            o[l]++;
            if(r!=n)o[r+1]--;
        }
        
        for(int i=1;i<n+1;i++)o[i]+=o[i-1];
        
        vector<pair<int, int>> v;
        v.resize(n+1);
        for(int i=0;i<n+1;i++){
            v[i].first = a[i];
            v[i].second = o[i];
        }
        sort(v.begin(), v.end());
        
        for(int i=1;i<n+1;i++){
            v[i].second+=v[i-1].second;
        }
        //sorting + prefix sum based idea for kth ele when you know freq of occurances of elements
        int f[n+1]={0};
        for(int i=0;i<n+1;i++)f[i]=v[i].second;
        
        while(q--){
            int x;
            cin>>x;
            if(x>f[n])cout<<-1<<" ";
            else{
                int idx = lower_bound(f, f+n+1, x)-(f);
                cout<<v[idx].first<<" ";
            }
        }
        cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
