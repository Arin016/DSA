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
#define int long long

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

void solve(){
        lli n;
        cin>>n;
        bitset<64> b;
        for(int i=63;i>=0;i--){
            if((n>>i)&1)b.set(i);
            else b.reset(i);
        }
        //operation 1
        for(int i=63;i>=0;i--){
            cout<<b[i];
        }
        cout<<endl;
        //operation 2
        int msb=-1;
        for(int i=63;i>=0;i--){
            if(b[i]){
                msb=i;
                break;
            }
        }
        if(n==0)cout<<-1<<endl;
        else cout<<msb<<endl;
        //operation 3
        int lsb=-1;
        for(int i=0;i<64;i++){
            if(b[i]){
                lsb=i;
                break;
            }
        }
        if(n==0)cout<<-1<<endl;
        else cout<<lsb<<endl;
        
        //operation 4
        if(__builtin_popcount(n)==1 && b[0]!=1)cout<<1<<endl;
        else cout<<0<<endl;
        //operation 5
        if(n!=0)cout<<(1<<lsb)<<endl;
        else cout<<-1<<endl;
        //operation 6
        if(n<=1)cout<<(1<<1)<<endl;
        else if(__builtin_popcount(n)==1)cout<<(1LL<<msb)<<endl;
        else cout<<(1LL<<(++msb))<<endl;
        
}

void solve1(){
    lli aandb,aorb;
    cin>>aandb>>aorb;
    cout<<aandb+aorb<<endl;
}

signed main(){
    #ifndef ONLINE_JUDGE
    setIO("az");
    #endif
    fio;
    int t=1;
    //cin>>t;
    while(t--){
        solve1();
    }
}