#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    int h, w, n;
    cin>>h>>w>>n;
    set<int> h1, w1; //positions of cuts
    multiset<int> h2, w2; //lengths we have
    h1.insert(0), h1.insert(h);
    w1.insert(0), w1.insert(w);
    h2.insert(h-0);
    w2.insert(w-0);
    while(n--){
        char x;
        int y;
        cin>>x>>y;
        if(x==('H')){
            h1.insert(y);
            auto it = h1.lower_bound(y);
            auto it1 = it, it2 = it;
            it1--, it2++;
            h2.erase(h2.find(abs(*it1-*it2)));
            h2.insert(abs(*it1-*it));
            h2.insert(abs(*it-*it2));
        }
        else{
            w1.insert(y);
            auto it = w1.lower_bound(y);
            auto it1 = it, it2 = it;
            it1--, it2++;
            w2.erase(w2.find(abs(*it1-*it2)));
            w2.insert(abs(*it1-*it));
            w2.insert(abs(*it-*it2));
        }
        auto maxw = w2.end(), maxh = h2.end();
        cout<<(*(w2.rbegin()))*(*(h2.rbegin()))<<endl;
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
