#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int kmp[n+1] = {0};
    kmp[0] = -1;
    int i = 0, j = -1;
    while(i < n){
        while(j != -1 && s[i] != s[j]) j = kmp[j];
        i++, j++;
        kmp[i] = j;
    }

    if(kmp[n] == 0){
        cout << -1 << endl;
        return;
    }

    string ans = s.substr(0, kmp[n]);  // This part is the longest prefix which is also a suffix

    // Check if this prefix (which is also a suffix) is found somewhere in the middle
    for(int i = 2; i < n; i++){
        if(kmp[i] == kmp[n]){
            cout << ans << endl;
            return;
        }
    }
    
    // If the largest prefix-suffix is not found in the middle, try the next possible smaller prefix-suffix
    if(kmp[kmp[n]] != 0){
        cout << s.substr(0, kmp[kmp[n]]) << endl;
    } else {
        cout << -1 << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
