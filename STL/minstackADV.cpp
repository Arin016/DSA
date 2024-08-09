#include<bits/stdc++.h>
using namespace std;
#define int long long

// Modulo value (though not used in this snippet, could be used for other parts of the problem)
int mod = 1e9+7;

// Structure to implement a stack with a minimum element retrieval feature
struct minstack {
    stack<int> st;  // Standard stack to store elements
    int minele;     // Variable to keep track of the minimum element in the stack

    // Initialize the stack and set minele to 0
    void init() {
        while (!st.empty()) st.pop();  // Clear the stack
        minele = 0;                    // Reset the minimum element
    }

    // Push a new element x onto the stack
    void push(int x) {
        if (st.empty()) {
            st.push(x);     // If the stack is empty, push x
            minele = x;     // Set minele to x
        } else {
            if (x >= minele) {
                st.push(x);  // If x is greater than or equal to minele, push x directly
            } else {
                // If x is smaller than minele, push a modified value to keep track of the previous minele
                st.push(2 * x - minele);
                minele = x;  // Update minele to the new minimum
            }
        }
    }

    // Pop the top element from the stack
    void pop() {
        int y = st.top();   // Get the top element
        st.pop();           // Pop the top element from the stack
        if (y < minele) {
            // If the top element is less than minele, restore the previous minimum
            minele = 2 * minele - y;
        }
    }

    // Return the current minimum element in the stack
    int mini() {
        return minele;
    }
};

// Function to solve the problem
void solve() {
    minstack ms;
    ms.init();
    int n;
    cin >> n;  // Read the number of elements
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;  // Read each element
        ms.push(x);  // Push the element onto the minstack
        cout << "Minimum so far: " << ms.mini() << endl;  // Output the current minimum
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;  // Read the number of test cases
    while (t--) {
        solve();  // Solve each test case
    }
}
