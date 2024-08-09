#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod = 1e9+7;


//naive idea wouldve been:
//1.cache map
//2.freq map
//3.set -> (recency, key)


//for lfu = cache map, freq map, set -> (freq, key)
//for lru = cache map, set -> (timer, key), timer map
struct LRUcache {
    list<int> order; // To maintain the order of keys based on access
    unordered_map<int, pair<int, list<int>::iterator>> cache; // key --> (value, iterator to list)
    int maxsize = 0;

    // Constructor to initialize the cache with a fixed capacity
    LRUcache(int capacity) {
        maxsize = capacity;
        order.clear();
        cache.clear();
    }

    // Moves the accessed key to the front of the order list
    void touch(int id) {
        auto it = cache.find(id);
        // Erase the current position of the key in the order list
        order.erase(it->second.second);
        // Move the key to the front of the list (most recently used)
        order.push_front(id);
        // Update the iterator in the cache map
        it->second.second = order.begin();
    }

    // Returns the value of the key if it exists, otherwise returns -1
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            touch(key); // Update the access order
            return cache[key].first; // Return the value associated with the key
        } else {
            return -1; // Key not found
        }
    }

    // Inserts or updates the key-value pair in the cache
    void put(int key, int value) {
        if (cache.find(key) == cache.end()) { // Key doesn't exist
            if (cache.size() == maxsize) { // Cache is full
                int del = order.back(); // Get the least recently used key
                cache.erase(del); // Remove it from the cache
                order.pop_back(); // Remove it from the order list
            }
            order.push_front(key); // Add the new key to the front of the list
            cache[key] = {value, order.begin()}; // Store the value and the iterator
        } else { // Key already exists
            touch(key); // Update the access order
            cache[key] = {value, order.begin()}; // Update the value
        }
    }
};

void solve() {
    // Solution function, implement problem-specific logic here
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
