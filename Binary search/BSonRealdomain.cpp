#include <iostream>
using namespace std;

// Assuming check() is a function already defined elsewhere that returns a boolean value
bool check(long double mid);

int main() {
    long double n;
    cin >> n;
    long double lo = 0, hi = n;

    for (int i = 0; i < 40; ++i) {
        long double mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    long double ans = (lo + hi) / 2;
    cout << ans << endl;

    return 0;
}