#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


/*
Description
Given are two sequences a={a0,…,aN−1} and b={b0,…,bN−1} of N non-negative integers each.

You will choose an integer k such that 0≤k<N and an integer x not less than 0, to make a new sequence of length N, a′={a′0,…,a′N−1}, as follows:

a′i=a(i+k)modN XOR x
Find all pairs (k,x) such that a′ will be equal to b.

Input Format
First line contains an integer N, 1 ≤ N ≤ 2*10^5.

Second line contains N space-separated integers,  0≤ ai < 2^30.

Third line contains N space-separated integers,  0≤ bi < 2^30.

Output Format
Print all pairs 
(
k
,
x
)
 such that 
a
′
 and 
b
 will be equal, using one line for each pair, in ascending order of 
k
 (ascending order of 
x
 for pairs with the same 
k
).

If there are no such pairs, the output should be empty.
*/

void solve(){

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
