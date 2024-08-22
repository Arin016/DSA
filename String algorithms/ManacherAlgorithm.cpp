#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

/*
The algorithm uses a temporary transformed string T by inserting a unique character (often #) 
between each character of S (including the ends) to handle even-length palindromes 
uniformly with odd-length ones. It then calculates an array P, 
where P[i] denotes the radius of the palindrome centered at T[i].
*/

void solve(){
    //number of substrings that are palindrome?
    //summation of all palindrome radii whose centres are positioned on characters and # positions

    //mc[i] = with this as centre whats the max length palindrome?
    //mc is constructed for intermediate manacher string with #

    //#1 
    //longest palindrome = max(mc[i])
    //#2
    //number of palindromic substrings
    //summationof((mc[i]+1)/2)
    //#3
    //is (l, r) a palindrome?
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
