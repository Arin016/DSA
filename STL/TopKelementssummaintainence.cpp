#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


struct bag{
    int k;
    priority_queue<int> pq;
    int sumk;
    void init(int _k){
        k = _k;
        sumk = 0;
    }
    void insert(int x){
        sumk+=x;
        pq.push(-x); //O(logn)
        if((int)(pq.size())>k){ //O(1)
            //typecasting is important (int)(pq.size()) otherwise it throws up error
            int smallestno = -pq.top(); //O(1)
            sumk-=smallestno; 
            pq.pop(); //O(logn)
        }
    }
    int topk(){
        return sumk;
    }

    //how are you going to support remove operation too ???
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
