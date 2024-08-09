#include <bits/stdc++.h>
using namespace std;
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


void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

lli binpowi(lli a, lli b, lli mod){
	a%=mod;
    lli res=1;
    while(b>0){
    	if(b&1){ 
        res = (res%mod*a%mod)%mod;
    	}
    	a = (a%mod*a%mod)%mod;
    	b>>=1;
    }
    return (res)%mod;
}

lli inverse(lli a, lli mod){
    return ((binpowi(a, mod-2, mod)%mod)+mod)%mod;
}


//its all about pnc + number of 0s and number of 1s at a specific bit position

void solve(){
	lli n;
	cin>>n;
	lli a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	lli ans1=0, ans2=0, ans3=0, ans4=0;
	lli val = binpowi(2, n-1, M)%M;
	for(int bit=0;bit<32;bit++){
		lli cnt[2]; cnt[0]=cnt[1]=0;
		for(int i=0;i<n;i++){
			cnt[(a[i]>>bit)&1]++;
		}
		ans1 = (ans1%M+(((cnt[0]%M*cnt[1]%M))*((1LL<<bit)%M))%M)%M;
		if(cnt[1]) ans2 = (ans2%M+(val%M*(1LL<<bit)%M)%M)%M;
		ans3 = (ans3%M+((cnt[1]%M*(cnt[1]-1)%M*inverse(2, M)%M)*(1LL<<bit)%M))%M;
		lli val1 = binpowi(2, cnt[1], M)%M;
		ans4 = (ans4%M+((val1-1+M)%M*(1LL<<bit)%M)%M)%M;
	}
	cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4<<endl;
}

int main(){
	#ifndef ONLINE_JUDGE
	setIO("az");
	#endif
	fio;
	//factorial(M);
	int _t=1;cin>>_t;while(_t--)
	solve();
}