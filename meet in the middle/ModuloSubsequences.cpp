#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> generateSums(vector<int> v, int m){
    vector<int> ans;
    int n = v.size();
    for(int mask=0;mask<(1LL<<n);mask++){
        int sum=0;
        for(int j=0;j<n;j++){
            if((mask>>j)&1){
                sum+=v[j];
                sum%=m;
            }
        }
        ans.push_back(sum);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

void solve(){
    int n,m,p;
    cin>>n>>m;
    vector<int> a;
    for(int i=0;i<n;i++){
        cin>>p;
        a.push_back(p);
    }
    vector<int> s1,s2;
    for(int i=0;i<a.size()/2;i++){
        s1.push_back(a[i]);
    }
    for(int i=(a.size()/2);i<n;i++){
        s2.push_back(a[i]);
    }
    vector<int> leftsums,rightsums;
    leftsums = generateSums(s1, m);
    rightsums = generateSums(s2, m);
    int idx;
    int val=-1e9;
    //in m's modular domain the numbers would be 0, 1, 2, 3, ......, m-1
    //we are BSing for making our final answer in m's modular domain i.e. 
    //leftsums[i]+rightsums[j] as close as possible to m-1
    //first element in rightsums that is > (m-1) - leftsums[i]
    for(int i=0;i<leftsums.size();i++){
        idx = upper_bound(rightsums.begin(), rightsums.end(), (m-1)-leftsums[i])-rightsums.begin();
        idx--;
        if(idx<rightsums.size()&&idx>=0)val = max(val, (leftsums[i]+rightsums[idx])%m);
    }
    cout<<val<<endl;
    
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}