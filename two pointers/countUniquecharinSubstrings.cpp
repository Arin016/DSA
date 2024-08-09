#include <bits/stdc++.h>
using namespace std;
#define int long long


int n;
string s;

//question was expecting 
//summation over all substrings (count of unique characters in that substring)
//using contribution technique we do it like:
//summation over all unique characters (number of strings they are part of)
//number of strings they are part of you can count in O(1) using indices (i-0+1)*(n-1-i+1)

//this is how you flip the quantities with summation and better the complexity

void solve(){
    cin>>n>>s;
    vector<vector<int>> h(26);
    for(int i=0;i<n;i++){
        h[s[i]-'a'].push_back(i);
    }
    int ans = 0;
    for(auto ind:h){
        int m = ind.size();
        if(m==0)continue;
        if(m==1){
            ans+=(ind[0]-0+1)*((n-1)-ind[0]+1);
        }
        else{
            for(int i=0;i<m;i++){
                int left, right;
                if(i==0){   //r-l+1
                    left =  ind[i]-0+1;//(i)-(0)+(1)
                    right = ind[i+1]-ind[i]+1-1; //(n-1)-(i)+(1) 
                }
                else if(i==m-1){
                    left = ind[i]-ind[i-1]+1-1;                                 
                    right = (n-1)-ind[i]+1;
                }
                else{
                    left = ind[i]-ind[i-1]+1-1; //-1 is so that we exclude the 'a' present at ind[i-1]
                    right = ind[i+1]-ind[i]+1-1; //-1 is so that we exclude the 'a' present at ind[i+1]
                }
                ans+=left*right;
            }
        }
    }
    cout<<ans<<endl;        
}


signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}



