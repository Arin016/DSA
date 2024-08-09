#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define endl '\n' 
#define int long long
#define ld long double 
#define IOS                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);


//maximisation problems:
//1111111111110000000000

//minimisation problems:
//0000000111111111111111
  
  
int a[100100], b[100100];
int n,k;

bool check(ld mid){
	priority_queue<ld> pq;
	for(int i=0;i<n;i++){
		pq.push(a[i]-mid*b[i]);
	}
	ld sum=0.0;
	for(int i=0;i<k;i++){
		sum+=pq.top();
		pq.pop();
	}
	return sum>=0;
}

void solve() {
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	long double lo=0.0,hi=1e8,mid;
        for(int i=0;i<69;i++)
        {
            mid = (lo+hi)/2.0;
            if(check(mid)){
                lo=mid;
            }else{
                hi=mid;
            }
        }
        //** remember "69" (lo+hi)/(2.0) and fixed setprecision */
    cout << fixed << setprecision(6) << (lo+hi)/(2.0) << "\n";
}


signed main(){
	IOS
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	
}