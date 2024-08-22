#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


//kmp[i] = look into s[0....i] what is the longest suffix that is also a prefix
//application:
//what to append to a string to make it a palindrome
//construction: rev(s)+@+s
//this gives us longest suffix that is a palindrome
//ans = s.size()-kmp.back()

void solve(){
    string s;
    cin>>s;
    int n = s.length();

    int kmp[n+1]; //1 indexed
    kmp[0] = -1;
    int i=0, j=-1;
    while(i<n){
        while(j!=-1 and s[i]!=s[j])j = kmp[j];
        i++, j++;
        kmp[i] = j;
    }
    //#1
    //pattern matching where and all t occurs in s?
    //apply kmp on t+#+s

    //in kmp whenevr the length of t occurs post # we can claim a match has happened


    //#2
    //find min number of characters to append at back to make it a palindrome
    //construction: rev(s)+#+s
    //this gives us longest suffix that is a palindrome
    //ans = s.size()-kmp[n]


    //#3
    //find period of a string s
    //smallest monomer = t
    //length of t = period
    //period vs extendible period(some part of the last monomer could be scarped out)
    //focus on last element of kmp array
    //for extendible period: n-kmp[n]
    //for period:
    //if(n%(n-kmp[n])==0)period = n-kmp[n];
    //else period = n;

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
