#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    map<vector<pair<int, int>>, int> mp;
    long long ans = 0;

    for(int i = 0; i < n; i++){
        vector<pair<int, int>> temp;
        int val = a[i];

        for(int j = 2; j * j <= val; j++){
            int p = 0;
            while(val % j == 0){
                val /= j;
                p++;
            }
            if(p % 3)
                temp.push_back({j, p % 3});
        }

        
        if(val > 1) {
            temp.push_back({val, 1});
        }

        
        vector<pair<int, int>> tofind;
        for(auto &x : temp){
            tofind.push_back({x.first, 3 - x.second});
        }

        
        ans += mp[tofind];

        
        mp[temp]++;
    }

    cout << ans << endl;
    return 0;
}
