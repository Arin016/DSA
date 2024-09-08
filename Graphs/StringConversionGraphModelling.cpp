#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
string s, en;
bool banstr[1<<20];
vector<int> g[(1<<20)];

int getval(string s){
    int stval = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1'){
            stval|=(1<<i);
        }
    }
    return stval;
}

void addedge(int x, int y){
    if(!banstr[x] and !banstr[y]){
        g[x].push_back(y);
        g[y].push_back(x);
    }
}
void solve(){
    cin>>s;
    int stval = getval(s);
    cin>>en;
    int enval = 0;
    int enval = getval(en);
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        string x;
        cin>>x;
        banstr[getval(x)] = 1;
    }
    for(int i=0;i<(1<<20);i++){ //for ith node
        for(int j=0;j<20;j++){ //for jth bit pos
            addedge(i, i^(1<<j));
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
