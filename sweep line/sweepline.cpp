#include<bits/stdc++.h>
using namespace std;

int main(){
    //used to process events in order
    //q-> total duration where no of people in the hall > k
    int n, k;
    cin>>n>>k;
    vector<pair<int, int>> events;
    for(int i=0;i<n;i++){
        int l, r;
        cin>>l>>r;
        events.push_back({l, +1});
        events.push_back({r, -1});
    }
    sort(events.begin(), events.end());
    
    int cnt = 0;
    int ans = 0;
    for(int i=0;i<events.size();i++){
        cnt+=events[i].second;
        if(i+1<events.size() and cnt>=k){
            ans+=events[i+1].first-events[i].first;
        }
    }
    cout<<ans<<endl;
}