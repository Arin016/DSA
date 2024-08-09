#include<bits/stdc++.h>
using namespace std;

int main(){
    //intersection would always be [max(li), min(ri)] and if(max(li)>min(ri)) then no intersection
    //union:
    int n;
    cin>>n;
    vector<pair<int, int>> events;
    for(int i=0;i<n;i++){
        int l, r;
        cin>>l>>r;
        events.push_back({l, +1});
        events.push_back({r, -1});
    }
    //we have to find out total union length and total intersection length
    sort(events.begin(), events.end());
    int cnt = 0;
    int uni = 0;
    int inter = 0;
    for(int i=0;i<events.size()-1;i++){
        cnt+=events[i].second; //cnt maintains number of active segments rn
        if(cnt>0){
            uni+=events[i+1].first-events[i].first;
        }
        if(cnt==n)inter+=events[i+1].first-events[i].first;
    }
    cout<<uni<<" "<<inter<<endl;
}