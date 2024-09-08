#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

class prioritize {
public:
    bool operator()(pair<int, int> p1, pair<int, int> p2){
        return p1.second<p2.second;
    }
};

void solve(){
    // Corrected: the second template argument should be vector<pair<int, int>>
    priority_queue<pair<int, int>, vector<pair<int, int>>, prioritize> pq;
    pq.push({2, 1});
    pq.push({1, 2});
    pq.push({1, 3});
    

    while(!pq.empty()){
        // Modified to print both elements of the pair
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    } 
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--){
        solve();
    }
}
