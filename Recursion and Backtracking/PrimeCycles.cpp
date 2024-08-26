#include <bits/stdc++.h>
using namespace std;

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
int visited[40];  // To handle differences, up to 37 - 1 = 36
int n;

int rec(int level, int prev) {
    // Base case: If we've constructed a sequence of length n
    if (level == n) {
        // Check if the last number and the first number sum to a prime
        for (auto x : primes) {
            if (x == (1 + prev)) {
                return 1;
            }
        }
        return 0;
    }

    // Compute
    int ans = 0;

    // Recursive case
    for (auto x : primes) {
        int curnumber = x - prev;
        if (curnumber > 0 && curnumber<=n && visited[curnumber] == 0) {  
            visited[curnumber] = 1;
            ans += rec(level + 1, curnumber);
            visited[curnumber] = 0;
        }
    }
    return ans;
}

void solve() {
    cin >> n;
    if(n%2!=0){
        cout<<0<<endl;
        return;
    }
    memset(visited, 0, sizeof(visited));  // Reset the visited array
    visited[1] = 1;
    int result = rec(1, 1);  // Start from level 1 with initial number 1
    cout << result << endl;  // Output the result
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
