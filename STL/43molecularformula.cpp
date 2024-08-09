#include<bits/stdc++.h>
using namespace std; 

signed main(){
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
        map<string,int> mp;
        string s;
        cin >> s;
        int n = s.size();
        string temp;   
        int fact = 1;
        int nom = 1;
        string num = "";
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(s[i] >= '0' && s[i] <= '9'){
                num = s[i] + num;
                nom = stoi(num);
                continue;
            }
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                temp = s[i] + temp;
                mp[temp]+=fact*nom;
                nom = 1;
                temp = "";
            }
            else if(s[i] >= 'a' && s[i] <= 'z'){
                temp = s[i] + temp;
            }
            else  if(s[i] == ')'){
                st.push(nom);
                fact *= nom;
                nom=1;
            }
            else if(s[i] == '('){
                fact = fact / st.top();
                st.pop();
            }
            num = "";
        }


        for(auto it:mp)
        {
            cout << it.first;
            if(it.second != 1)cout << it.second;
        }   
        cout << endl;
    }
    return 0;
}