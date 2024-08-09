#include<bits/stdc++.h>
using namespace std;


//count number of subarrays and stuff--> SCREAMS two pointers!!!!!!!!!!!
long long func(long long x, vector<long long> a)
{
    int n=a.size();
    int head=-1, tail=0;
    long long sum=0;
    long long tot=0;
    while(tail<n)
    {
        while(head+1<n && (sum+a[head+1])<=x )
        {
            head++;
            sum+=a[head];
        }
        tot+=(head-tail+1);
        if(head>=tail)
        {
            sum-=a[tail];
            tail++;
        }
        else
        {
            tail++;
            head = tail-1;
        }
    }
    return tot;
}
void solve()
{
    long long n;
    cin>>n;
    vector<long long> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long l=0, r=0;
    for(int i=0;i<n;i++)
    {
        r+=a[i];
    }
    long long num = (n*(n+1))/2;
    long long med = (num+1)/2;
    long long ans=-1;
    while(l<=r)
    {
        long long mid = l+ (r-l)/2;
        long long tot = func(mid, a);
        if(tot>=med)
        {
            ans = mid;
            r=mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    cout<<ans<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}