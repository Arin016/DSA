#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second




//all subset sums -> summation(ai)*(2^(n-1))
//each elements contribution -> ai*(2^(n-1))
//all submasks sums -> summation(ai)*(3^(n-1))
//a&b + a|b = a+b
//c = a&b and d = a|b
//in this when you choose two numbers(a, b) and take their and(a&b=c) and or(a|b=d) what happens is when you take or(|) all the set
//bits which are set in only one amongst a or b gets transferred to c and when you take and(&) all the zeroes  
//imagine this like gravity flip

//ex =   1010      1010
//     | 1100    & 1100
//       1110      1000


//maths observation:
//x+y = 5
//max(x^2+y^2) = ??

//its always better to choose x = 5 and y = 0, this holds true everywhere

void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int cnt[22]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<22;j++){
            if((a[i]>>j)&1)cnt[j]++;
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        int val = 0;
        for(int j=0;j<22;j++){
            if(cnt[j]){
                val+=(1<<j);
                cnt[j]--;
            }
        }
        ans+=(val*val);
    }
    cout<<ans<<endl;
}

signed main(){
    solve();
}