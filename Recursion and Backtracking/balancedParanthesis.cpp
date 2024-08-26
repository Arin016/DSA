#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;



int n, k; //balanced paranthesis with depth = k
vector<char> sol;

void rec(int level, int c, int uc){
    //base case
    if(level==n){
        if(c==uc){
            int d = 0;
            int maxd = 0;
            for(auto x:sol){
                if(x=='(')d++;
                else d--;
                maxd = max(maxd, d);
            }
            if(maxd==k){
                for(auto x:sol)cout<<x;
                cout<<endl;
            }
        }
        return;
    }
    //recursive case
    //put c
    sol.push_back('(');
    rec(level+1, c+1, uc);
    sol.pop_back();
    //put uc
    if(c>uc){
        sol.push_back(')');
        rec(level+1, c, uc+1);
        sol.pop_back();
    }
}




void solve(){
    cin>>n>>k;
    rec(0, 0, 0);
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
