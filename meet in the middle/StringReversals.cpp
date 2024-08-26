#include<bits/stdc++.h>
using namespace std;
#define int long long

void generate1(int k, string s, map<string, int>& mp){
    //base case
    if(k==0){
        mp[s] = 1;
        return;
    }
    //recursive case
    //for all choices
    for(int i=0;i<s.length();i++){
        for(int j=i;j<s.length();j++){
            if(1){
                //make the move
                reverse(s.begin()+i, s.begin()+j+1);
                //check furthur
                generate1(k-1, s, mp);
                //revret
                reverse(s.begin()+i, s.begin()+j+1);
            }
        }
    }
}

void solve(){
	string s,t;
	cin>>s>>t;
	map<string, int> mp1;
	map<string, int> mp2;
    generate1(2, s, mp1);
    generate1(2, t, mp2);
    bool flag = false;
   	for(auto x:mp1){
   		if(mp2.find(x.first)!=mp2.end()){
   			flag = true;
   			break;
   		}
   	}
   	if(flag)cout<<"YES"<<endl;
   	else cout<<"NO"<<endl;
}


signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}