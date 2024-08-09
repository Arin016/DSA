#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


void solve(){
    string s;
    cin>>s;
    bool isbalanced = true;
    map<char, int> mp;
    mp['('] = +1;
    mp['['] = +2;
    mp['{'] = +3;
    mp[')'] = -1;
    mp[']'] = -2;
    mp['}'] = -3;
    stack<int> st;
    for(auto x:s){
        if(mp[x]>0){
            st.push(mp[x]);
        }
        else{
            if(!st.empty() and st.top()+x==0){
                continue;
            }
            else{
                isbalanced = false;
                break;
            }
        }
    }
    if(isbalanced and st.empty())cout<<"YES"<<endl; //checking if t
    else cout<<"NO"<<endl;

    //empty check is really important beforehand so that it doesnt throw up seg fault


    //have a menatl picture of the mountain with x axis to be the indices of brackets and the y axis to be
    //depth values
    //if we are supposed to check for a specific range if its balanced or not the value of depth lets assume was k at those points
    //then for it to be balanced all the depth values must lie above the line y=k and the end and start point must have a depth k
    //this simply means there were k unclosed brackets at the begining of the range and there still are k unclosed brackets at 
    //the end of this range
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
