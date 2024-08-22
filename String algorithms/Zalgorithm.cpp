#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

//converts a string to an array
//len of array = len of string
//z[i] = len of longest substring starting at i that is a prefix of s


vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}


void solve(){
    //how many instances of string t is present in string s?
    //construction: t+'@'+s
    //throw it into Z!
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
