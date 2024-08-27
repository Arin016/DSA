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

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int n,k;
int a[100100];
int f[100100];
int distcnt=0;

void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int head=-1,tail=0;
    
    int ans=0;
    
    while(tail<n){
        while(head+1<n && ((f[a[head+1]]==0 && distcnt<k)||(f[a[head+1]]!=0 && distcnt<=k))){
            head++;
            if(f[a[head]]==0)distcnt++;
            f[a[head]]++;
        }
        
        int len = head-tail+1;
        ans += len;
        
        if(head>=tail){
            f[a[tail]]--;
            if(f[a[tail]]==0)distcnt--;
            tail++;
        }
        else{
            tail++;
            head = tail-1;
        }
    }
    cout<<ans<<endl;
}

signed main(){
    #ifndef ONLINE_JUDGE
    setIO("problemname");
    #endif
    fio;
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}