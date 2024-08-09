#include<bits/stdc++.h>
using namespace std;
#define F first 
#define S second 

using event = pair<pair<int, int>, pair<int, int>>; 

/*
event type -->{{start, eventype}, {value, bogus value}}
event type : 0 = start, 1 = query, 2 = end //including the borders case
event type : 2 = start, 1 = query, 0 = end //excluding the borders case
*/
int main(){
    int n;
    cin>>n;
    vector<event> events;
    for(int i=0;i<n;i++){
        int l, r, x;
        cin>>l>>r>>x;
        events.push_back({
            {l, 0}, {x, i}
        });
        events.push_back({
            {r, 2}, {x, i}
        });
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int y, k;
        cin>>y>>k;
        events.push_back({
            {y, 1}, {k, i}
        });
    }
    sort(events.begin(), events.end());

    vector<int> ans(q);
    multiset<int> mt;
    for(auto x:events){
        if(x.F.S==0){ //if this is a start position of a range
            mt.insert(x.S.F);
        }
        else if(x.F.S==2){ //if this is an end position of a range
            mt.erase(mt.find(x.S.F));
        }
        else{
            // if this is a query
            int val = 0;
            int cnt = 0;
            for(auto it = mt.rbegin();it!=mt.rend() and cnt<=x.S.F;it++){
                val+=*it;
                cnt++;
            }
            ans[x.S.S] = val;
        }
    }

    for(auto x: ans){
        cout<<x<<" ";
    }
    cout<<endl;
}