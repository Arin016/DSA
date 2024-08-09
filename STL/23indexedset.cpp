#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
/*
    order_of_key (k)
    find_by_order(k)
*/

signed main() {
  // freopen("IN", "r", stdin);
  // freopen("OUT", "w", stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin >> T;

  while (T--) {
    int Q;
    cin >> Q;

    ordered_set s;

    while (Q--) {
      string op;
      int x;
      cin >> op >> x;

      if (op == "add") {
        s.insert(x);
      } else if (op == "remove") {
        if (s.find(x) != s.end()) {
          s.erase(s.find(x));
        }
      } else if (op == "find") {
        if (x >= (int)s.size()) {
          cout << "-1\n";
        } else {
          cout << *(s.find_by_order(x)) << "\n";
        }
      } else {
        cout << s.order_of_key(x) << "\n";
      }
    }
  }
  return 0;
}