#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, L;
    cin>>n>>L;
    vector<pair<int, int>> events;
    for(int i=0;i<n;i++){
        int l, r;
        cin>>l>>r;
        events.push_back({l, +1});
        events.push_back({r, -1});
    }
    sort(events.begin(), events.end());
    int ans = n+1;
    int cnt = 0;
    for(int i=0;i<events.size()-1;i++){
        cnt+=events[i].second; //number of segments open rn
        if(events[i].first!=events[i+1].first){
            ans = min(ans, cnt);
        }
        if(events[i].first>L)break; //you dont have to check for segments for points that lie after L
    }
    //our aim is to calculate the min number of segments across all the points in total range
    cout<<n-ans+1<<endl;
    //n->total number of segments
    //-ans->i can take out this number across all points in range then at some places number of segments for those points get to 0 but we want atleast 1 segment over it thus....
    //+1
    
}