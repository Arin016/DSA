#include<bits/stdc++.h>
using namespace std;
#define int long long

//counting the frequency of an element in a sorted array, UB(x)-LB(x)

void solve(){
    int n, t;
    cin>>n>>t;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a, a+n);
    int cnt = 0;
    for(int j=0;j<n;j++){
        int i = 0;
        int k = n-1;
        while(i<j and k>j){
            if(a[i]+a[j]+a[k]==t){
                //cnt++;
                //i++;
                //k--;
                int itemp = i, ktemp = k;
                while(itemp<j and a[itemp]==a[i])itemp++;
                while(ktemp>j and a[ktemp]==a[k])ktemp--;
                cnt+= (itemp-i)*(k-ktemp);
                i = itemp;
                k = ktemp;
            }
            else if(a[i]+a[j]+a[k]<t){
                i++;
            }
            else k--;
        }
    }
    if(cnt)cout<<true<<endl;

}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
