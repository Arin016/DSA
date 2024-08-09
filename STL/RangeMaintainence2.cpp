#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

#define F first
#define S second

struct range_maintenance {
    set<pair<int, int>> ranges; // A set to store ranges as pairs
    //O(logq) per query!!!
    // Function to add a range [l, r] and merge overlapping ranges
    void fillrange(int l, int r) {
        // Merge with any overlapping ranges to the left
        auto it = ranges.upper_bound({l, 1e9});
        if (it != ranges.begin()) {
            it--;
            if (it->second >= l) { // If the segment's end point goes beyond l
                l = it->first;
                r = max(it->second, r);
                ranges.erase(it);
            }
        }

        // Merge with any overlapping ranges to the right
        it = ranges.upper_bound({r, 1e9});
        if (it != ranges.begin()) {
            it--;
            if (it->second >= r) { // If the segment's end point goes beyond r
                r = it->second;
                l = min(l, it->first);
                ranges.erase(it);
            }
        }

        // Remove any ranges that are fully contained within [l, r]
        while (true) {
            auto it = ranges.lower_bound({l, 0});
            if (it == ranges.end() || it->first > r) break;
            ranges.erase(it);
        }
        ////you always have to handle these three cases
        //          ------------------------------------------
        //     ----------         ----------           ----------

        //deleting all those seg's in between
        // Insert the new merged range
        ranges.insert({l, r});
    }

    // Function to clear a range [l, r] and handle edge cases
    void clearrange(int l, int r) {
        // Handle the left boundary case
        auto it = ranges.upper_bound({l, 1e9});
        if (it != ranges.begin()) {
            it--;
            //this is an extra case for clearrange thats a one off here
            //--------------------------------
            //     -------------------  //i wish to delete this range
            if (it->second >= r) { // If the range fully contains [l, r]
                int lo1 = it->first;
                int hi1 = l;
                int lo2 = r;
                int hi2 = it->second;
                ranges.erase(it);
                if (lo1 < hi1) ranges.insert({lo1, hi1});
                if (lo2 < hi2) ranges.insert({lo2, hi2});
                return;
            }
            if (it->second >= l) { // If the segment's end goes beyond l
                int lo = it->first;
                int hi = l;
                ranges.erase(it);
                if (lo < hi) ranges.insert({lo, hi});
            }
        }

        // Handle the right boundary case
        it = ranges.upper_bound({r, 1e9});
        if (it != ranges.begin()) {
            it--;
            if (it->second >= r) { // If the segment's end goes beyond r
                int lo = r;
                int hi = it->second;
                ranges.erase(it);
                if (lo < hi) ranges.insert({lo, hi});
            }
        }
        ////you always have to handle these three cases
        //          ------------------------------------------
        //     ----------         ----------           ----------

        //deleting all those seg's in between
        // Remove all segments fully contained within [l, r]
        while (true) {
            auto it = ranges.lower_bound({l, 0});
            if (it == ranges.end() || it->first >= r) break;
            ranges.erase(it);
        }
    }

    // Function to check if a point x is within any range
    bool checkpoint(int x) {
        auto it = ranges.upper_bound({x, 1e9});
        if (it == ranges.begin()) return false;
        it--;
        return it->second >= x;
    }

    // Function to check if any part of the range [x, y] is covered
    bool checkrangeany(int x, int y) {
        auto it = ranges.upper_bound({x, 1e9});
        //segment starts after x [UB]
        //segment starts before y
        if (it != ranges.end() && it->first <= y) return true;
        return checkpoint(x); //if some segment is starting before x then still that range (x, y) has a segment
    }

    // Function to check if the entire range [x, y] is covered
    bool checkrangeall(int x, int y) {
        auto it = ranges.upper_bound({x, 1e9});
        if (it == ranges.begin()) return false;
        it--;
        return it->second >= y;
    }

    // Function to print the current status of ranges
    void printstatus() {
        cout << "Current status: ";
        for (auto x : ranges) {
            cout << "(" << x.first << ", " << x.second << ") ";
        }
        cout << endl;
    }
};

// Function to handle input and execute range maintenance operations
void solve() {
    //fill range l, r merge all segments  possible in l, r
    //clear range l, r clear active points in this range
    //check point x if this point is active
    //check interval inside x, y if any point is active in x, y
    int q;
    cin >> q;
    //this is called creating an instance of the structure
    range_maintenance rm; // Create an instance of the range_maintenance structure
    while (q--) {
        int ch;
        cin >> ch;
        if (ch == 1) { // Fill range operation
            int l, r;
            cin >> l >> r;
            rm.fillrange(l, r);
        } else if (ch == 2) { // Clear range operation
            int l, r;
            cin >> l >> r;
            rm.clearrange(l, r);
        } else if (ch == 3) { // Check point operation
            int x;
            cin >> x;
            cout << rm.checkpoint(x) << endl;
        } else if (ch == 4) { // Check if any part of range [x, y] is covered
            int x, y;
            cin >> x >> y;
            cout << rm.checkrangeany(x, y) << endl;
        } else { // Check if entire range [x, y] is covered
            int x, y;
            cin >> x >> y;
            cout << rm.checkrangeall(x, y) << endl;
        }
        rm.printstatus(); // Print current status after each operation
    }
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
