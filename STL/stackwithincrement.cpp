#include<bits/stdc++.h>
using namespace std;
#define int long long

// Modulo value for any operations that might need it in future extensions
int mod = 1e9+7;

// Custom stack structure with an additional "increment" feature
struct stackwithincrement{
    vector<pair<int, int>> st; // Vector of pairs to store (value, increment)
    int curtop;                // Points to the next available index in the stack

    // Initialize the stack with a given maximum size
    void init(int maxsize){
        st.clear();          // Clear any existing elements
        st.resize(maxsize);  // Resize to the maximum size needed
        curtop = 0;          // Start with the stack being empty
    }

    // Push a value onto the stack
    void push(int x){
        if(curtop < st.size()){        // Ensure we don't exceed stack size
            st[curtop] = {x, 0};       // Store the value with an initial increment of 0
            curtop++;                  // Move to the next position
        }
    }

    // Pop a value from the stack
    int pop(){
        if(curtop != 0){               // Ensure the stack is not empty
            curtop--;                  // Move the top pointer back
            st[curtop].first += st[curtop].second;  // Apply any pending increments

            // Propagate the increment to the next lower element
            if(curtop-1 >= 0){
                st[curtop-1].second += st[curtop].second;
            }
            return st[curtop].first;   // Return the popped value
        } else {
            return -1;  // If the stack is empty, return -1
        }
    }

    // Increment the bottom `k` elements of the stack by `val`
    void increment(int k, int val){
        k = min(curtop, k);  // Ensure k does not exceed the current stack size
        k--;
        if(k >= 0) st[k].second += val; // Apply the increment to the k-th element
    }
};

// Main problem-solving function
void solve(){
    // Example operations for the stack
    int maxsize = 5;  // Example maximum size
    stackwithincrement stk;
    stk.init(maxsize);
    
    // Perform example operations
    stk.push(1);
    stk.push(2);
    stk.increment(2, 3);  // Increment bottom 2 elements by 3
    cout << stk.pop() << "\n";  // Should return 5 (2+3)
    cout << stk.pop() << "\n";  // Should return 4 (1+3)
    cout << stk.pop() << "\n";  // Should return -1 (stack is empty)
}

signed main(){
    ios_base::sync_with_stdio(0);  // Fast IO
    cin.tie(0);                    // Untie cin from cout
    cout.tie(0);                   // Untie cout from cin

    int t=1;  // Number of test cases
    cin>>t;
    while(t--){
        solve();  // Solve each test case
    }
}
