#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n;
string l, r;
int m, d;
string a, b;

int dp[2000][2][2][2002][3];

int rec(int level, int tlo, int thi, int modd, int ins){
    //base case
    if(level == n){
        return modd == 0;
    }
    //cache check
    if(dp[level][tlo][thi][modd][ins]!=-1)return dp[level][tlo][thi][modd][ins];
    //compute
    int ans = 0;
    int lo = 0, hi = 9;
    if(tlo == 1) lo = l[level] - '0';
    if(thi == 1) hi = r[level] - '0';

    for(int i = lo; i <= hi; i++){
        int newthi = thi, newtlo = tlo;
        if(i != lo) newtlo = 0;
        if(i != hi) newthi = 0;

        if(ins == 0){
            if(i == 0){
                ans = (ans + rec(level + 1, newtlo, newthi, (modd * 10 + i) % m, 0)) % mod;
            }
            else {
                if(i != d) ans = (ans + rec(level + 1, newtlo, newthi, (modd * 10 + i) % m, 2)) % mod;
            }
        }
        else{
            if(ins == 2 && i==d) {
                ans = (ans + rec(level + 1, newtlo, newthi, (modd * 10 + i) % m, 1)) % mod;
            }
            else if(ins == 1 && i != d){
                ans = (ans + rec(level + 1, newtlo, newthi, (modd * 10 + i) % m, 2)) % mod;
            }
        }
    }
    return dp[level][tlo][thi][modd][ins] = ans;
}

void solve(){
    cin >> m >> d;
    cin >> a >> b;
    r = b;
    int zeroes = b.length() - a.length();
    string extra = "";
    while(zeroes--){
        extra += '0';
    }
    l = extra + a;
    n = l.length();
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 1, 1, 0, 1) << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
