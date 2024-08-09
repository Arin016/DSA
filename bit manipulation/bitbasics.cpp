#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

/*
get me the last x digits of a number n: n%(1<<x)

to take 2s compliment: take 1s compliment (~x) i.e. flip bits then add 1

-x = ~x+1

set -> x = x|(1<<i)
unset -> x = x&(~(1<<i))
check -> (x&(1<<i)>0) or ((x>>i)&1==1)
flip -> x = x^(1<<i)
count -> __builtin_popcount(x);  __builtin_popcountll(x);

whilst you run loops take it till 31

x = x&(x-1)  it turns off the rightmost set bit
int set_bit = x&(~(x-1)) restores the lsb and blows off the rest

xor of numbers from 1....n -->n%4--> 0 = (n), 1 = (1), 2 = (n+1), 3 = (0) -->f(n)

xor of continous ranges -->[l, r] = f(r)^f(l-1)


n+i = n^i
xor is addition without carry
thus to obtain the same value when added with and without carry there must be no carry
count number of unset bits in n in 0...log2(n), let x then ans is 1<<x


the frequency of an index i when considering all possible subarrays is (i+1)*(n-i)


min value of xor of ai and aj would be --> sort and take min across all ai*ai+1, adjacent elements


for 0th bit it alternates after 1 position 0 1 0 1 0 1
for 1st bit it alternates after 2 position 0 0 1 1 0 0
for 2nd bit it alternates after 4 position 0 0 0 0 1 1 1 1


sum of all set bits in 0....n or number of set bits in 0....n-->
for each bit i,  (n/(2^(i+1)))*2^i + max((n%((2^(i+1))))-2^i, 0)

bitset<8> temp(12);
cout<<temp.to_string()<<endl;

if number of bits exceeds 64 then you could use bitset

bitset<4> x("1001");
bitset<8> other(0b11001010);
intValue = bits.to_ulong();
bits.to_string(); 
the number of bits i.e. 4 in this case must be fixed and it cant be dynamic


PREFER RIGHT SHIFTS >>

[0, 30] when looping

*/
signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    int val = 0;
    while (q--) {
        int t, i;
        cin >> t;
        if (t == 1) {
            cin >> i;
            cout << ((val >> i) & 1) << endl;
        }
        if (t == 2) {
            cin >> i;
            val |= (1LL << i);
        }
        if (t == 3) {
            cin >> i;
            val &= (~(1LL << i));
        }
        if (t == 4) {
            cin >> i;
            val ^= (1LL << i);
        }
        if (t == 5) {
            if (__builtin_popcountll(val) == 60) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
        if (t == 6) {
            if (__builtin_popcountll(val) >= 1) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
        if (t == 7) {
            if (__builtin_popcountll(val) == 0) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
        if (t == 8) {
            cout << __builtin_popcountll(val) << endl;
        }
        if (t == 9) {
            cout << val << endl;
        }
    }
    return 0;
}

#undef int







