#include<bits/stdc++.h>
using namespace std;

#define int long long
int mod = 1e9+7;

void solve() {
    int n;
    cin >> n;
    multiset<int> a;
    for (int i = 0; i < (1<<n); i++){
        int x;
        cin >> x;
        a.insert(x);
    }

    multiset<int> og, done;
    done.insert(0);
    a.erase(a.find(0));

    while(!a.empty()){
        int cur = *a.begin();
        og.insert(cur);
        multiset<int> temp;
        for(auto x : done){
            temp.insert(x + cur);
        }
        for(auto x : temp){
            done.insert(x);
            a.erase(a.find(x));
        }
    }

    for(auto x : og){
        cout << x << " ";
    }
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
