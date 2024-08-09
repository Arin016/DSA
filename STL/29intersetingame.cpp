#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

bool comp(pair<int, int> &a, pair<int, int> &b){
    return a.first+a.second>b.first+b.second;
}

//if both have to play optimally then
//lets say scoreA = 0 and scoreB = summ(bi) initially
//scoreA-scoreB = 0-summ(bi)
//when we move one card from bob to alice itll change to
//scoreA = ai and scoreB = summ(bi)-bi
//scoreA-scoreB = ai-(summ(bi)-bi)
//scoreA-scoreB = (ai+bi) - summ(bi)
//ai+bi is the value by which the diff in score changes thus this 
//needs to be the condition according to which we sort

void solve(){
    int n;
    cin>>n;
    int a[n], b[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    vector<pair<int, int>> v(n);
    for(int i=0;i<n;i++){
        v[i].first = a[i];
        v[i].second = b[i];
    }
    sort(v.begin(), v.end(), comp);
    int al = 0, bo = 0;
    for(int i=0;i<n;i++){
        if(i&1)bo+=v[i].second;
        else al+=v[i].first;
    }
    if(al>bo){
        cout<<"Alice"<<endl;
    }
    else if(al==bo){
        cout<<"Tie"<<endl;
    }else{
        cout<<"Bob"<<endl;
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
