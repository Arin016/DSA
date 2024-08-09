#include <bits/stdc++.h>
using namespace std;

class SnapshotArray {
public:
    // Map to store index with their corresponding snapshot versions
    // index -> {(snapid, val), (snapid, val), (snapid, val)}
    map<int, vector<pair<int, int>>> arr;
    int n;  // Length of the array
    int timer = 0;  // Snapshot ID counter

    // Constructor to initialize the SnapshotArray with a given length
    SnapshotArray(int length) {
        n = length;
    }

    // Method to set a value at a given index for the current snapshot
    void set(int index, int val) {
        // If the last update at this index is in the current snapshot, replace it
        if (!arr[index].empty() && arr[index].back().first == timer) {
            arr[index].pop_back();
        }
        // Add the new value with the current snapshot ID
        arr[index].push_back({timer, val});
    }

    // Method to take a snapshot and return the snapshot ID
    int snap() {
        timer++;  // Increment the snapshot counter
        return timer - 1;  // Return the snapshot ID (0-based index)
    }

    // Method to get the value at a given index for a specific snapshot
    int get(int index, int snap_id) {
        if (arr[index].empty()) return 0;  // If no value is set, return 0

        // Use upper_bound to find the first entry with a snapshot ID greater than snap_id
        auto it = upper_bound(arr[index].begin(), arr[index].end(), make_pair(snap_id, 1000000010));
        
        // If no such entry exists, return 0
        if (it == arr[index].begin()) {
            return 0;
        } else {
            it--;  // Move to the previous entry (since upper_bound gives the first greater element)
            return (*it).second;  // Return the value of that entry
        }
    }
};

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int Q, L;
    cin >> Q >> L;

    // Initialize the SnapshotArray with the given length
    SnapshotArray snapshotArray(L);

    while (Q--) {
        string op;
        cin >> op;

        if (op == "set") {
            int index, val;
            cin >> index >> val;

            // Set the value at the given index
            snapshotArray.set(index, val);
        } else if (op == "get") {
            int index, snap_id;
            cin >> index >> snap_id;

            // Get the value at the given index for the specific snapshot ID
            cout << snapshotArray.get(index, snap_id) << "\n";
        } else if (op == "snap") {
            // Take a snapshot and print its ID
            cout << snapshotArray.snap() << "\n";
        }
    }

    return 0;
}
