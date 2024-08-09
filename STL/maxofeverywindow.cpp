#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

// struct monotoneDq{
//     deque<int> dq;
//     void insert(int x){
//         while(!dq.empty() and dq.back()>x){
//             dq.pop_back();
//         }
//         dq.push_back(x);
//     }
//     void erase(int x){
//         if(dq.front()==x)dq.pop_front();
//     }
//     int getmin(){
//         return dq.front();
//     }
// };

struct monotoneDqmax{
    deque<int> dq;
    void insert(int x){
        while(!dq.empty() and dq.back()<x){
            dq.pop_back();
        }
        dq.push_back(x);
    }
    void erase(int x){
        if(dq.front()==x)dq.pop_front();
    }

    int getmax(){
        return dq.front();
    }
};


//you couldve negated the number and used mindq too

void solve(){
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    monotoneDqmax mdq;
    for(int i=0;i<n;i++){
        mdq.insert(a[i]);
        if(i-k>=0)mdq.erase(a[i-k]);
        if(i>=(k-1))cout<<mdq.getmax()<<" ";
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
