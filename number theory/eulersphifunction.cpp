#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;



//largest power of prime p in n!
//power of p in n! is n/p + n/(p^2) + n/(p^3) + ..... n/(p^k)


//number of zeroes at the end of n!
//== largest power of 10 that divides n!
//==min(largest power of 2 that divides n!, largest power of 5 that divides n!)
set<int> factorise(int x){
	set<int> ans;
	for(int i=2;i*i<=x;i++){
		if(!(x%i)){
			ans.insert(i);
			while(!(x%i)){
				x/=i;
			}
		}
	}
	if(x!=1)ans.insert(x);
	return ans;
}

signed main(){
	int n;
	cin>>n;
	int val = n;
	set<int> ans = factorise(n);
	for(auto it=ans.begin();it!=ans.end();it++){
		val*=(*it-1);
		val/=(*it);
	}
	cout<<val<<endl;
}