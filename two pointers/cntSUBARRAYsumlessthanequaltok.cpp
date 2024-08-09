#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, k;
int a[1000100];

void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    int head = -1, tail = 0;
    int sum = 0;
    int ans = 0;
    while(tail<n){
        while(head+1<n and sum+a[head+1]<=k){
            head++;
            sum+=a[head];
        }
        ans+=(head-tail+1);
        if(head>=tail){
            sum-=a[tail];
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
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}