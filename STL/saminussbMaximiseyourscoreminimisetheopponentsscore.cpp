#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


bool comp(pair<int, int> &a, pair<int, int> &b){
    //condition true for a before b
    //dont use = symbol in this func return statement
    return a.first+a.second>b.first+b.second;
}

void solve(){
    int n;
    cin>>n;
    //lets assume b had all the cards then sa = 0, sb = summ(bi)
    //lets say we shift one card from the hands of b to a then sa-sb = ai-(summ(bi)-bi)
    //sa-sb = (ai+bi)-summ(bi), this increased the value of sa by ai+bi thus picking according to values of ai+bi
    //would be optimal
    vector<pair<int, int>> cards(n);
    for(int i=0;i<n;i++){
        cin>>cards[i].first>>cards[i].second;
    }
    sort(cards.begin(), cards.end(), comp);
    //stable_sort() --> maintains the order from the given array
    //when they play optimally now they pick alterate values from the sorted vector (acc to comp).
    
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
