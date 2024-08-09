#include <bits/stdc++.h>
using namespace std;
#define int long long

bool comp(pair<int,int>&a, pair<int,int>&b) {
    if(a.first == b.first) {
        return a.second > b.second;
    } else {
        return a.first < b.first;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, L;
    cin >> n >> L;
    vector<pair<int, int>> intervals;
    
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        intervals.push_back({a, b});
    }
    
    // Sort intervals with custom comparator
    sort(intervals.begin(), intervals.end(), comp);
    
    int count = 0;
    int covered = 0;
    int i = 0;
    
    while(covered < L) {
        int furthest = covered;
        
        // Try to extend the coverage as far as possible with the next interval
        while(i < n && intervals[i].first <= covered) {
            furthest = max(furthest, intervals[i].second);
            i++;
        }
        
        
        // Extend coverage and increment count of intervals used
        covered = furthest;
        count++;
    }
    
    cout << count << endl;
    return 0;
}