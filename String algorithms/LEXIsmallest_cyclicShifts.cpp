#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

//amongst all the cyclic shifts find out the lexicographically smallest one
//whenever there's cyclic shifts and stuffs, always think of appending it twice!!

struct hasher {
    string s;
    int n, mod, p;
    vector<int> fhash, rhash, pk;

    void init(const string& _s, int _p, int _mod) {
        s = _s;
        n = s.length();
        mod = _mod;
        p = _p;
        fhash.assign(n, 0);
        rhash.assign(n, 0);
        pk.assign(n, 0);
        fhash[0] = (s[0] - 'a' + 1);
        rhash[n-1] = (s[n-1] - 'a' + 1);
        pk[0] = 1;
        for (int i = 1; i < n; i++) {
            fhash[i] = (fhash[i - 1] * p % mod + (s[i] - 'a' + 1)) % mod;
            rhash[(n - 1 - i)] = (rhash[(n - 1 - i) + 1] * p % mod + (s[(n - 1 - i)] - 'a' + 1)) % mod;
            pk[i] = (pk[i - 1] * p) % mod;
        }
    }

    int getfhash(int l, int r) {
        int hash_val = fhash[r];
        if (l - 1 >= 0) {
            hash_val = (hash_val - fhash[l - 1] * pk[r - l + 1] % mod + mod) % mod;
        }
        return hash_val;
    }

    int getRhash(int l, int r) {
        int hash_val = rhash[l];
        if (r + 1 < n) {
            hash_val = (hash_val - rhash[r + 1] * pk[r - l + 1] % mod + mod) % mod;
        }
        return hash_val;
    }
};

int n;
hasher shash1, shash2;
string s;

bool check(int mid, int i, int j){
    return (shash1.getfhash(i, i+mid-1) == shash1.getfhash(j, j+mid-1)) &&
           (shash2.getfhash(i, i+mid-1) == shash2.getfhash(j, j+mid-1));
}

bool cmp(int i, int j){
    // Binary search on answer for common length for string starting at i vs string starting at j
    int lo = 1, hi = n, ans = 0;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(check(mid, i, j)){
            ans = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    if(ans == n) return i>j; // You could've returned 0/1 too; it doesn't matter because both are the same strings that started from i and j
    else{
        return s[i + ans] < s[j + ans];
        // Never use '=' in returns in custom comparators
        // Write such a statement whose value, if true, would put i before j while sorting
    }
}

void solve(){
    // Basically all the binary search is done to reduce the string comparison from O(n) to O(logn)
    cin >> s;
    n = s.length();
    s = s + s;
    //use double hash to avoid collission when length is 1e5>=
    shash1.init(s, 37, 999999937);
    shash2.init(s, 31, 999999929); // (s, 29, 999999931)
    //29, 31, 37
    // We are using two shash so that the probability of getting WA reduces massively
    vector<int> ans;
    for(int i = 0; i < n; i++){
        ans.push_back(i);
    }
    sort(ans.begin(), ans.end(), cmp);
    for(auto x : ans){
        cout << x << " ";
    }
    cout << endl;

    //to check simple string matching:
    //st = 0, en = st+m-1
    //till en<=n-1 run a for loop
    // for(int st=0;st+len-1<n;st++){

    // }

    //collission probab:
    //(no of unique string accessed)/(MOD)
    //extraa:
    //to check if l...r is a palindrome if forwardhash is equal to reverse hash then its palindrome
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
