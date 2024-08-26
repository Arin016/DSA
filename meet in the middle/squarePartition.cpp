#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<int> arr;
vector<int> part1, part2;

int rec(int level, int a, int b, int c, int d) {
    // base case
    if(level == n) {
        if(a == b && b == c && c == d) return 1;
        return 0;
    }
    // compute
    int ans = 0;
    // recursive case
    ans += rec(level + 1, a + arr[level], b, c, d);
    ans += rec(level + 1, a, b + arr[level], c, d);
    ans += rec(level + 1, a, b, c + arr[level], d);
    ans += rec(level + 1, a, b, c, d + arr[level]);
    return ans;
}

vector<pair<pair<int, int>, pair<int, int>>> abcdposs;
void recabcd(int level, int a, int b, int c, int d) {
    // base case
    if(level == part1.size()) {
        abcdposs.push_back({{a, b}, {c, d}});
        return;
    }
    // recursive case
    // here automatic reverts are happening 
    recabcd(level + 1, a + part1[level], b, c, d);
    recabcd(level + 1, a, b + part1[level], c, d);
    recabcd(level + 1, a, b, c + part1[level], d);
    recabcd(level + 1, a, b, c, d + part1[level]);
}

vector<pair<pair<int, int>, pair<int, int>>> pqrsposs;
void recpqrs(int level, int p, int q, int r, int s) {
    // base case
    if(level == part2.size()) {
        pqrsposs.push_back({{p, q}, {r, s}});
        return;
    }
    // recursive case
    // here automatic reverts are happening 
    recpqrs(level + 1, p + part2[level], q, r, s);
    recpqrs(level + 1, p, q + part2[level], r, s);
    recpqrs(level + 1, p, q, r + part2[level], s);
    recpqrs(level + 1, p, q, r, s + part2[level]);
}

void solve() {
    cin >> n;
    arr.resize(n);
    // given n rods can you combine them all to form a square?
    int total = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        total += arr[i];
        if(i & 1) part1.push_back(arr[i]);
        else part2.push_back(arr[i]);
    }
    // split the total of those n sticks into 2 partitions
    // generate all possible a,b,c,d and p,q,r,s by both the partitions
    // and iterate on all possible a,b,c,d and check if tot/4-a, tot/4-b, tot/4-c, tot/4-d exists in 
    // p, q, r, s!
    recabcd(0, 0, 0, 0, 0);
    recpqrs(0, 0, 0, 0, 0);
    map<pair<pair<int, int>, pair<int, int>>, int> mp;
    for(auto x : pqrsposs) {
        mp[x]++;
    }
    int val = total / 4;
    bool flag = false;
    for(auto x : abcdposs) {
        if(mp[{{val - x.first.first, val - x.first.second}, {val - x.second.first, val - x.second.second}}]) {
            flag = true;
            break;
        }
    }
    if(total % 4 == 0 && flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}
