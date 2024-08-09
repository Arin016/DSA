#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define F first 
#define S second 
#define PB push_back 
#define endl "\n"
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define setpre(x, n) fixed << setprecision(x) << n
using lli = long long;
const lli INF = LLONG_MAX >> 1;
const lli M = 1000000007;
#define int long long

 // Phase 1: Find all primes in the range [1...sqrt(b)] and Collect small primes up to sqrt(b)
 // Phase 2: Sieve the range [a...b] using the primes in [1...sqrt(b)]

bool is_prime[1000001];
vector<int> primes;

void sieve(){	
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= 1e6; p++){
        if (is_prime[p]){
            for (int i = p * p; i <= 1e6; i += p)
                is_prime[i] = false;
        }
    }
    for (int i = 2; i <= 1e6; i++){
        if (is_prime[i])
            primes.push_back(i);
    }
}

void segmented_sieve(int L, int R, vector<int> &res){
	sieve();
    bool check[R - L + 1];
    memset(check, true, sizeof(check));
    for (int p : primes){
        int curr_mul = ((L + p - 1) / p) * p;
        while (curr_mul <= R){
            if (p != curr_mul)check[curr_mul - L] = false;
            curr_mul += p;
        }
    }
    if (L == 1){
        check[0] = false;
    }
    for (int i = 0; i < R - L + 1; i++){
        if (check[i])
            res.push_back(L + i);
    }
}

void solve(){
	int l,r;
	cin>>l>>r;
	vector<int> res;
	segmented_sieve(l,r,res);
	cout<<res.size()<<endl;
	for(auto x:res)cout<<x<<" ";
	cout<<endl;
}

signed main(){
	fio;
	//int _t=1;cin>>_t;while(_t--)
	solve();
}