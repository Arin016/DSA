#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

inline void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}

inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += mod;
}

inline int mul(int a, int b) {
  return (int) ((long long) a * b % mod);
}

inline int power(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

inline int inv(int a) {
  a %= mod;
  if (a < 0) a += mod;
  int b = mod, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += mod;
  return u;
}

//an element in the range l to r could be Ai*k^(i-L)
//for each query [L, R] a[L]+=A and a[R+1]-=A*k^(R-L+1)
//when you take prefix sum use a[i]+=a[i-1]*k
//split and kill constat terms and linear seperately

//THIS CONCLUDES PARTIAL SUMS AND PREFIX SUMS IN 1D
//ALSO INCLUDES PARTIAL SUMS AND PREFIX SUMS WITH AP GP VARIATIONS
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, q, k;
    cin >> n >> q >> k;
    int A[n + 2];
    memset(A, 0, sizeof(A));

    while(q--) {
        int a, l, r;
        cin >> a >> l >> r;
        add(A[l], mul(a, inv(power(k, l)))); 
        //to set up the threshold that we dont want in that range we are dividing by k^l
        sub(A[r + 1], mul(a, inv(power(k, l))));
    }

    for(int i = 1; i <= n; i++) {
        add(A[i], A[i - 1]);
        //pre computing these kpoweri initially (i+1)th val = ith val * k
        //total cost wouldve been logn+n
        //and after that for each query wouldve been O(1) instead of logn
        cout << mul(A[i], power(k, i)) << " ";
    }
    cout << "\n";

    return 0;
}

