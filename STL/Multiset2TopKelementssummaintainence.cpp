#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


struct bag{
    int k;
    multiset<int> mt1, mt2;
    int sumk;

    void init(int _k){
        k = _k;
        sumk = 0;
        mt1.clear();
        mt2.clear();
    }

    void insert(int x){
        mt1.insert(x);sumk+=x;

        if(mt1.size()>k){
            sumk-=*(mt1.begin());
            mt2.insert(*(mt1.begin()));
            mt1.erase(mt1.begin());
        }
    }

    void remove(int x){
        if(mt1.count(x)){
            sumk-=x;
            mt1.erase(mt1.find(x));
        }
        else if(mt2.count(x)){
            mt2.erase(mt2.find(x));
        }

        if(mt1.size()<k and !mt2.empty()){
            sumk+=*(mt2.rbegin());
            mt1.insert(*(mt2.rbegin()));
            auto it = mt2.end();
            it--;
            // mt2.erase(mt2.rbegin()); whenever you want to erase you just cant use rbgein and delete
            mt2.erase(it);
        }
    }

    int getsumk(){
        return sumk;
    }
};

void solve(){
    //this cant be done with one multiset!
    int k;
    cin>>k;
    bag bg;
    bg.init(k);
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        string s;
        cin>>s;
        if(s=="insert"){
            int x;
            cin>>x;
            bg.insret(x);
        }
        else if(s=="remove"){
            int x;
            cin>>x;
            bg.remove(x);
        }
        else cout<<bg.getsumk()<<endl;
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
