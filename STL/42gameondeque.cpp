#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    int n, q;
    cin>>n>>q;
    deque<int> dq(n);
    int maxi = -1e9;
    for(int i=0;i<n;i++){
        cin>>dq[i];
        maxi = max(maxi, dq[i]);
    }
    int ind=0;
    for(int i=0;i<n;i++){
        if(dq[i]==maxi){
            ind = i;
            break;
        }
    }
    vector<pair<int, int>> ans;
    // ans.push_back({1e9, 1e9}); //why??? --> because we want the answers from x=1 and not from x=0
    for(int i=0;i<=ind;i++){
        int x = dq.front();
        dq.pop_front();
        int y = dq.front();
        dq.pop_front();
        ans.push_back({x, y});
        if(x>y){
            dq.push_front(x);
            dq.push_back(y);
        }
        else{
            dq.push_front(y);
            dq.push_back(x);
        }
    }
    //once the ele with maximum value occupies the first pos itd never let go and all the other 
    //elemnts will start revolving around it with a periodicity of n-1
    dq.pop_front();
    //blowed up the maxi
    while(q--){
        int x;
        cin>>x;
        x--;
        if(x<ans.size()){
            cout<<ans[x].first<<" "<<ans[x].second<<endl;
        }
        else{
            cout<<maxi<<" "<<dq[(x-ans.size())%(n-1)]<<endl;
        }
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
