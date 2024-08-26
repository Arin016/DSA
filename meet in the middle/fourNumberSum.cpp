#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


//for any nsum probelm:
//when n is even X+Y == T conversion
//when n is odd fix one number and the rest becomes an even nsum problem
// a+b+c+d == T
//  X+Y == T

void solve1(){
    //you can pick same index multiple times
    int n, target;
    cin>>n>>target;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    map<int, int> mp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mp[a[i]+a[j]] = 1;
        }
    }
    bool flag = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mp[target - (a[i]+a[j])]==1){
                flag = true;
            }
        }
    }
    cout<<flag<<endl;
}

void solve2(){
    //you cant pick same index multiple times, # of possible solutions?
    int n, target;
    cin>>n>>target;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    //keep a partition in the array, from left side of the partition pick a, the element just left 
    //of the partition is b and c+d we'd get from right side of the array
    map<int, int> mp;
    int cnt = 0;
    for(int b=n-2;b>=1;b--){ //the b wich was on left of partition
        for(int a=b-1;a>=0;a--){ //the a's which were to the left of b
            if(mp[target-(arr[a]+arr[b])]==1)cnt+=mp[target-(arr[a]+arr[b])]; //check is such a c, d exist
        }
        int c = b; //moving the partition and updating the arr[c]+arr[d] values in the map
        for(int d=c+1;d<n;d++){
            mp[arr[c]+arr[d]]++;
        }
    }
    if(cnt){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}


void solve3(){
    //you cant pick same index multiple times and also find those indices
    int n, target;
    cin>>n>>target;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    //keep a partition in the array, from left side of the partition pick a, the element just left 
    //of the partition is b and c+d we'd get from right side of the array
    map<int, pair<int, int>> mp; //(sum, indices that were responsible)
    pair<pair<int, int>, pair<int, int>> fans;
    for(int b=n-2;b>=1;b--){ //the b wich was on left of partition
        for(int a=b-1;a>=0;a--){ //the a's which were to the left of b
            if(mp.find(target-(arr[a]+arr[b]))!=mp.end()){
                pair<int, int> ans = mp[target-(arr[a]+arr[b])];
                fans = {{a, b}, {ans.first, ans.second}};
            } //check is such c, d exist
        }
        int c = b; //moving the partition and updating the arr[c]+arr[d] values in the map
        for(int d=c+1;d<n;d++){
            mp[arr[c]+arr[d]]={c, d};
        }
    }
    cout<<fans.first.first<<" "<<fans.first.second<<" "<<fans.second.first<<" "<<fans.second.second<<endl; 
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve2();
    }
}
