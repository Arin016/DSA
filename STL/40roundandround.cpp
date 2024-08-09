#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int x = 0, y = 0, dir = 0;
    //dir--> 0 = N 1 = E 2 = S 3 = W
    for(int i=0;i<n;i++){
        if(s[i]=='L'){
            //only dir changes
            dir-=1;
            dir%=4;
        }
        else if(s[i]=='R'){
            //only dir changes
            dir+=1;
            dir%=4;
        }
        else{
            dir+=4;
            dir%=4;
            //getting the dir in our domain if at all it has gone out
            if(dir==0){
                y++;
            }
            else if(dir==1){
                x++;
            }
            else if(dir==2){
                y--;
            }
            else{
                x--;
            }
        }
    }
    if((x==0 and y==0)){
        cout<<"YES"<<endl;
    }
    else if(!(x==0 and y==0) and dir!=0){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
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
