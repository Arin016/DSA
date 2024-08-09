//summation over all substrings (number of distinct char in it)
//summation over all dist char (number of substring they are part of)
/*
We need to calculate the contribution of each letter from ‘a’ to ‘z’ to the final answer. For the answer, we will consider the case for ‘a’, you need to do the same for each letter from ‘a’ to ‘z’. If the count of ‘a’ is anything more than 0 in a subarray, it would contribute 1 to the final answer (since we are taking count of distinct characters). So, we can first add the total number of subarrays, N*(N+1)/2 to the final answer and then subtract those subarrays which don’t have the character ‘a’ in it. This would give us the contribution for ‘a’ in the final answer. Do the same for all characters from ‘a’ to ‘z’.
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<vector<int>> indx(26);
    for(int i=0;i<n;i++){
        indx[s[i]-'a'].push_back(i);
    }
    int ans = 26*(((n)*(n+1))/2);
    //for counting the number of subarrays of which "a" per say is not a part and subtracting it from n*(n+1)/2 that belonged to a
    for(auto v:indx){
        vector<int> temp = v;
        int m = temp.size();
        if(m==0){
            ans -= (n*(n+1))/2;
        }else if(m==1){
            int left = temp[0]-0;
            int right = n-temp[0]-1;
            ans -= (left*(left+1))/2;
            ans -= (right*(right+1))/2;
        }else{
            for(int i=0;i<m;i++){
                int left;
                int right;
                if(i==0){
                    left = temp[i]-0;
                    right = temp[i+1]-temp[i]-1;
                    ans -= (left*(left+1))/2;
                    ans -= (right*(right+1))/2;
                }else if(i==m-1){
                    left = temp[i]-temp[i-1]-1;
                    right = n-temp[i]-1;
                    ans -= (right*(right+1))/2;
                }else{
                    left = temp[i]-temp[i-1]-1;
                    right = temp[i+1]-temp[i]-1;
                    ans -= (right*(right+1))/2;
                }
                
            }
        }

    }

    cout<<ans<<endl;

}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

