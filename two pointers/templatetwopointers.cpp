#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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


//to count number of subarrays with >k 0s use complimentary method
//total number of subarrays n+1c2 = a
//subarrays with 0s <=k, use two pointer approach = b
//ans = a-b
//to count number of subarrays with ==k 0s 
//subarrays with 0s <=k, use two pointer approach = b1
//subarrays with 0s <=k-1, use two pointer approach = b2
//ans = b1-b2

//two pointers calculates the head-tail+1 values for all possible values of tail, given a tail where its best head would be is known by Two pointers

void solve(){
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i]; 
    
    //DS for two pointers condition checking checking
	map<int, int> mp;
    int ans = 0; //store the max length of the window
    //pointers 
    int head=-1, tail=0;
    //T.C = O(N*(h+a+t))
    while(tail<n){
        //while there is a next element to take and we wont violate any condition
        while(head+1<n && (mp.size()<k || mp.count(a[head+1]))){ //HOW WOULD IT AFFECT OUR DATASTRUCTURE
        //O(h)
            head++;
            mp[a[head]]++;   //part to change
        }
        //update the answer accordingly
        //O(a)
        ans = (ans+head-tail+1);   //part to change
        //move tail ahead and remove the last elements contribution
        //O(t)
        if(head>=tail){
        	//part to change
			mp[a[tail]]--;
            if(mp[a[tail]]==0)mp.erase(mp.find(a[tail]));
            tail++;
            //reverse the O(h) part replace the head with tail and maintain the ds appropriately
        }
        else{
            tail++;
            head = tail - 1;
        }
    }
    cout<<ans<<endl;
}

signed main(){
    fio;
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}