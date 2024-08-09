#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


struct bag1{
    int sum = 0;
    multiset<int> mst;
    set<int> st;
    void insert(x){
        sum+=x;
        st.insert(x);
        mst.insert(x);
    }
    int summation(){
        return sum;
    }
    int getmax(){
        return *(st.begin());
    }
    int dist(){
        return st.size();
    }
    void remove(int x){
        sum-=x;
        mst.erase(mst.find(x));
        if(mst.count(x)==0)st.erase(x);
    }
};

struct bag2{
    int sum = 0;
    map<int, int> f;
    void insert(x){
        sum+=x;
        f[x]++;
    }
    int summation(){
        return sum;
    }
    int getmax(){
        return (*f.rbegin()).first;
    }
    int dist(){
        return (int)(f.size());
    }
    void remove(int x){
        sum-=x;
        f[x]--;
        if(f[x]==0)f.erase(f.find(x));
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
