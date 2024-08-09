#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> ans(n);
    multiset<int> mt;
    int b = 1;
    for(int i=0;i<n;i++){
        mt.insert(a[i]);
        while(!mt.empty() and *(mt.begin())<=b){ //****
            mt.erase(mt.begin());
        }
        if(mt.size()>b)b++; //b can atmax increase by 1
        ans[i] = b;
    }

    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
