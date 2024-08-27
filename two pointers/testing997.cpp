#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n, x;
	    cin>>n>>x;
	    int a[n];
	    int sum = 0;
	    for(int i=0;i<n;i++)cin>>a[i];
	    int cnt = 0;
	    for(int i=0;i<n;i++){
	        if(a[i]>=x)cnt++;
	        if(a[i]>x){
	            sum+=a[i]-x;
	            a[i] = x;
	        }
	    }
	    // if(cnt==n){
	    //     cout<<n<<endl;
	    //     continue;
	    // }
	   // cout<<"sum"<<sum<<endl;
	    sort(a, a+n);
	    if(sum==0){
	        int cnt = 0;
	        for(int i=0;i<n;i++){
	            if(a[i]>=x)cnt++;
	        }
	        cout<<cnt<<endl;
	    }
	    else{
	       // for(int i=0;i<n;i++)cout<<a[i]<<" ";
	       // cout<<endl;
	        int i=n-1;
	        while(i>=0){
	            if(a[i]==x){
	                i--;
	            }
	            else{
	                int req = x-a[i];
	                if(sum>=req){
	                    sum-=req;
	                    a[i] = x;
	                    i--;
	                }
	                else{
	                    break;
	                }
	            }
	        }
	       // for(int i=0;i<n;i++)cout<<a[i]<<" ";
	       // cout<<endl;
	        int cnt = 0;
	        for(int i=0;i<n;i++){
                if(a[i]==x)cnt++;
            }
            cout<<cnt<<endl;
	    }
	    
	}

}