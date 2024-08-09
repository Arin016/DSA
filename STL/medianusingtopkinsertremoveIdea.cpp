#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;



struct bag{
    multiset<int> mt1, mt2;
    //mt1 keeps lower values and mt2 keeps the higher ones
    void init(){
        mt1.clear();
        mt2.clear();
    }

    void insert(int x){
        if(!mt1.empty()){
            if(x<=*(mt1.rbegin())){
                mt1.insert(x);
                return;
            }
        }
        if(!mt2.empty()){
            if(x>=*(mt2.begin())){
                mt2.insert(x);
                return;
            }
        }
        //if both of them are empty i.e. initially or the number lies between max of mt1 and min of mt2
        //then itll go in mt1
        mt1.insert(x);
    }

    void remove(int x){
        if(!mt1.empty()){
            if(x<=*(mt1.rbegin())){
                mt1.erase(mt1.find(x));
                return;
            }
        }
        if(!mt2.empty()){
            if(x>=*(mt2.begin())){
                mt2.erase(mt2.find(x));
                return;
            }
        }
    }
    //if both of them are empty i.e. initially or the number lies between max of mt1 and min of mt2
        //then itll go in mt1
    //the inequality that mt1 is always bigger than mt2
    void rebalance(){
        while(mt1.size()>=mt2.size()+2){
            auto it = mt1.end();
            it--;
            mt2.insert(*it);
            mt1.erase(it);
        }
        while(mt2.size()>mt1.size()){
            auto it = mt2.begin();
            mt1.insert(*it);
            mt2.erase(it);
        }
    }

    int getmedian(){
        rebalance();
        //the inequality that mt1 is always bigger than mt2
        auto it = mt1.end();
        it--;
        return *it;
    }
};
void solve(){
    //dynamic array maintainence --> two multisets
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
