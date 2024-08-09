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

int n,d;
int a[2000100];
int f[2000100];

void solve(){
    cin>>n>>d;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int head=-1,tail=0;
    int ans=1e9;

    //data structure
    int len = 0;
    int dcnt = 0;
    
    while(tail<n){
        while(head+1<n && len<d){
            head++;
            len++;
            if(f[a[head]]==0)dcnt++;
            f[a[head]]++;
        }
        
        if(head-tail+1==d)ans = min(ans, dcnt);
        
        if(head>=tail){
            f[a[tail]]--;
            len--;
            if(f[a[tail]]==0)dcnt--;
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
    fio;
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}