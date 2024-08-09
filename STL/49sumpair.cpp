#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


struct FindPairswithSum{
    vector<int> a, b;
    map<int, int> f; //key -> bj value -> freq

    FindPairswithSum(vector<int>& a1, vector<int>& b1){
        a.clear();
        b.clear();
        a = a1;
        b = b1;
        f.clear();
        for(int i=0;i<b.size();i++)f[b[i]]++;
    }

    void add(int index, int val){
        f[b[index]]--;
        f[b[index]+val]++;
        b[index]+=val;
    }

    int count(int total){
        int cnt = 0;
        for(int i=0;i<a.size();i++){
            cnt+=f[total-a[i]];
        }
        return cnt;
    }

};


void solve(){

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
