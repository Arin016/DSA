#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

bool check(int mid, vector<int>& a){
    if(mid==a.size()-1)return 1;
    return a[mid]>a[mid+1];
}

void solve(){
    int n, q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    while(q--){
        int k;
        cin>>k;
        int peak = -1;
        int lo = 0, hi = n-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(check(mid, a)){
                peak = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        if(a[peak]==k)cout<<peak+1<<endl;
        else{
            int pos1 = -1, pos2 = -1;
            int lo = 0, hi = peak-1;
            while(lo<=hi){
                int mid = lo+(hi-lo)/2;
                if(a[mid]==k){
                    pos1 = mid+1;
                    break;
                }
                else if(a[mid]>k)hi = mid-1;
                else lo = mid+1;
            }
            int lo1 = peak+1, hi1 = n-1;
            while(lo1<=hi1){
                int mid = lo1+(hi1-lo1)/2;
                if(a[mid]==k){
                    pos2 = mid+1;
                    break;
                }
                else if(a[mid]>k)lo1 = mid+1;
                else hi1 = mid-1;
            }
            if(pos1!=-1 and pos2!=-1){
                cout<<pos1<<" "<<pos2<<endl;
            }
            else if(pos1==-1)cout<<pos2<<endl;
            else if(pos2==-1)cout<<pos1<<endl;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}

