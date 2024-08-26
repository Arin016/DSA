#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


//O(n!)

int n;
vector<int> queens;

bool check(int row, int col){
    for(int i=0;i<n;i++){
        if(queens[i]!=-1){
            if(row==i||col==queens[i]||abs(row-i)==abs(col-queens[i])){
                return false;
            }
        }
    }
    return true;
}

//level, choice, check, move(make change, go ahead, revert)
int rec(int level){
    //base case
    if(level>=n){
        return 1;
    }
    int ans = 0;
    //recursive case
    for(int col=0;col<n;col++){
        if(check(level, col)){
            queens[level] = col;
            ans+=rec(level+1);
            queens[level] = -1;
        }
    }
    return ans;
}

void solve(){
    cin>>n;
    queens.assign(n, -1);
    cout<<rec(0)<<endl;
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
