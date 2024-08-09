#include <bits/stdc++.h>
using namespace std;

bool check(int mid, vector<int>& consecutiveDifference, int n, int ub, int lb) {
    vector<int> ans;
    ans.push_back(mid);
    for(int i = 0; i < n; i++) {
        ans.push_back(-consecutiveDifference[i] + ans.back());
    }
    for(auto x : ans) {
        if(x > ub || x < lb) return false;
    }
    return true;
}

int countAnalogousArrays(vector<int>& consecutiveDifference, int lowerBound, int upperBound) {
    int n = consecutiveDifference.size();
    int lo = lowerBound, hi = upperBound, ans = lowerBound-1;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if(check(mid, consecutiveDifference, n, upperBound, lowerBound)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans - lowerBound + 1;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int lb, ub;
    cin >> lb >> ub;
    cout << countAnalogousArrays(a, lb, ub) << endl;
    return 0;
}
