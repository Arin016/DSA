#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(int t){
    int n;
    cin>>n;
    string s;
    cin>>s;

    int kmp[n+1] = {0};
    kmp[0] = -1;
    int i=0, j=-1;
    while(i<n){
        while(j!=-1 and s[i]!=s[j])j = kmp[j];
        i++, j++;
        kmp[i] = j;
    }

    cout<<"Test case #"<<t<<endl;
    for(int i=1;i<n+1;i++){
        int plen = i-kmp[i];
        if(i%plen==0 and kmp[i]!=0){
            //i%plen = to check for perfect period
            //kmp[i] = to ignore the initial period
            cout<<i<<" "<<i/plen<<endl;
        }
    }
    cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    int T = 1;
    while(t--){
        solve(T);
        T++;
    }
}
