#include<bits/stdc++.h>
using namespace std;


void solve1(){
    int n;
    cin>>n;
    int a[n];
    string ans;
    for(int i=0;i<n;i++){
        cin>>a[i];
        ans+="*";
    }
    for(int i=0;i<n;i++){
        if(a[i]==1){
            if(i+1<n and i-1>=0){
                if(ans[i+1]!='x' and ans[i-1]!='x')ans[i] = 'x';
            }
            else if(i==0){
                if(ans[i+1]!='x')ans[i] = 'x';
            }
            else if(i==n-1){
                if(ans[i-1]!='x')ans[i] = 'x';
            }
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]==2){
            if(i+1<n and i-1>=0){
                if(ans[i+1]!='y' and ans[i-1]!='y')ans[i] = 'y';
            }
            else if(i==0){
                if(ans[i+1]!='y')ans[i] = 'y';
            }
            else if(i==n-1){
                if(ans[i-1]!='y')ans[i] = 'y';
            }
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]==3){
            if(i+1<n and i-1>=0){
                if(ans[i+1]=='y' and ans[i-1]=='y')ans[i] = 'x';
                else if(ans[i+1]=='x' and ans[i-1]=='x')ans[i] = 'y';
                else if(ans[i+1]=='x' and ans[i-1]=='y')continue;
                else if(ans[i+1]=='y' and ans[i-1]=='x')continue;
                else ans[i] = 'x';
            }
            else if(i==0){
                if(ans[i+1]=='y')ans[i] = 'x';
                if(ans[i+1]=='x')ans[i] = 'y';
            }
            else if(i==n-1){
                if(ans[i-1]=='y')ans[i] = 'x';
                if(ans[i-1]=='x')ans[i] = 'y';
            }
        }
    }
    cout<<ans<<endl;
    int cnt = 0;
    for(auto x:ans)if(x=='*')cnt++;
    cout<<cnt<<endl;
}

int main(){
    cout<<log2(1e9)<<endl;
}