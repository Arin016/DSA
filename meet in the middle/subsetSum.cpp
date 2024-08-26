#include <bits/stdc++.h>
using namespace std;
#define int long long

//indicator for MIM--> why n<=40 instead of n<=20???

vector<int> generate(const vector<int>& a) {
    vector<int> ans;
    int n = a.size();
    for(int i = 0; i < (1 << n); i++) {
        int sum = 0;
        for(int k = 0; k < n; k++) {
            if((i >> k) & 1) {
                sum += a[k];
            }
        }
        ans.push_back(sum);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a[2];
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i & 1].push_back(x);  // Split into two groups based on even/odd index
    }
    
    vector<int> leftsums = generate(a[0]);
    vector<int> rightsums = generate(a[1]);
    
    
    int cnt = 0;
    for(auto x : leftsums) {
        // Count how many values in rightsums make sum <= k
        auto it = upper_bound(rightsums.begin(), rightsums.end(), k - x);
        cnt += distance(rightsums.begin(), it);
    }
    
    cout << cnt << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}
