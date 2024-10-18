#include<bits/stdc++.h>
using namespace std;

string a, b;
int n, m;

int dp[1001][1001];
int rec(int i, int j){ 
	//LCS considering 0....i in a and 0....j in b
	//pruning
	//base case
	if(i<0 || j<0){
		return 0;
	}
	//we are computing for all the dp[levels], there exists no base case as such
	//cache check
	if(dp[i][j]!=-1)return dp[i][j];
	//compute/transition
	int ans = max(rec(i-1, j), rec(i, j-1));
	if(a[i]==b[j]){
		ans = max(ans, rec(i-1, j-1)+1);
	}
	//save and return
	return dp[i][j] = ans;
}

void solve(){
	cin>>a;
	b = a;
	reverse(b.begin(), b.end());
	n = a.length();
	m = n;
	
	// m = b.size();
	memset(dp, -1, sizeof(dp));
    //seeee this!!!!!!!! N-LCS(s, reverse(s))!
	cout<<n-rec(n-1, m-1)<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}