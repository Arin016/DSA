#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define endl '\n' 
#define int long long
#define IOS                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
void solve(){
	set<int> st1, st2;
	int q;
	cin>>q;
	while(q--){
		int s;
		cin>>s;
		if(s==1){
			int x;
			cin>>x;
			st1.insert(x);
			st2.erase(x);
			if(st1.find(x+1)==st1.end())st2.insert(x+1);
		}
		else if(s==2){
			int x;
			cin>>x;
			if(st1.find(x)==st1.end())cout<<x<<endl;
			else cout<<(*st2.lower_bound(x))<<endl;
		}
	}
	
}

signed main(){
	IOS
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	
}