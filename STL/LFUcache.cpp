#include<bits/stdc++.h>
using namespace std;
#define int long long // Using int64_t for handling larger numbers
int mod = 1e9+7;

// Structure to implement LFU Cache
struct LFUcache {
    int maxsize, size, lfu; // maxsize is the cache capacity, size is the current number of items, lfu tracks the least frequently used key
    unordered_map<int, list<int>> keys; // Maps frequency to a list of keys with that frequency
    unordered_map<int, pair<int, int>> values; // Maps key to a pair (value, frequency)
    unordered_map<int, list<int>::iterator> iters; // Maps key to its position in the frequency list

    // Function to update the frequency of a key
    void update(int key) {
        int freq = values[key].second; // Get current frequency
        auto it = iters[key]; // Get iterator to the key in the frequency list
        values[key].second++; // Increment the frequency
        keys[freq].erase(it); // Remove the key from the old frequency list
        keys[freq+1].push_back(key); // Add the key to the new frequency list
        iters[key] = --keys[freq+1].end(); // Update the iterator to the new position of the key
        if(keys[lfu].empty()) lfu++; // If the old least frequently used list is empty, increase lfu
    }

    // Constructor to initialize the cache with a given capacity
    LFUcache(int capacity) {
        maxsize = capacity;
        size = 0;
        lfu = 0;
    }
    
    // Function to get the value of a key
    int get(int key) {
        if(values.find(key) == values.end()) {
            return -1; // Return -1 if key is not found
        } else {
            update(key); // Update the key's frequency if found
            return values[key].first; // Return the value associated with the key
        }
    }

    // Function to add a key-value pair to the cache
    void put(int key, int value) {
        if(values.find(key) != values.end()) {
            // If key is already present
            values[key].first = value; // Update the value
            update(key); // Update the key's frequency
        } else {
            // If key is not present
            if(maxsize == size) {
                // If cache is full, remove the least frequently used key
                int del = keys[lfu].front(); // Get the least frequently used key
                keys[lfu].pop_front(); // Remove it from the frequency list
                values.erase(del); // Erase the key-value pair
                iters.erase(del); // Erase the iterator
            } else {
                size++; // Increase the size of the cache
            }
            // Insert the new key with value and initial frequency 1
            values[key] = {value, 1};
            keys[1].push_back(key);
            iters[key] = --keys[1].end(); // Store the iterator to the key's position
            lfu = 1; // Reset the least frequently used frequency to 1
        }
    }
};

void solve() {
    // Your test cases or logic goes here
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}
