#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;



struct monotoneDq{
    deque<int> dq;
    void insert(int x){
        while(!dq.empty() and dq.back()>x){
            dq.pop_back();
        }
        dq.push_back(x);
    }
    void erase(int x){
        if(dq.front()==x)dq.pop_front();
    }
    int getmin(){
        return dq.front();
    }
};

void solve(){
    //when you processing window by window once a smaller element comes in the already present larger elements
    //can never be the answer

    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //every element is put into dq only once and removed only once thus o(n+n) -> O(2*n)
    monotoneDq mdq;
    for(int i=0;i<n;i++){
        //insert
        mdq.insert(a[i]);
        //delete
        //(i-k)th element should be removed from our window 
        if(i-k>=0)mdq.erase(a[i-k]); //thinking about these to get formulaes think about index "zero"
        //print for the window
        if(i>=(k-1)){
            cout<<mdq.getmin()<<endl;
        }
    }

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
