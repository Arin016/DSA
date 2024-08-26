#include <bits/stdc++.h>
using namespace std;
//if there's something that you need to have or need to check at each and every level then pass it along with the level in the function parameter space

vector<char> pos = {'A','B','C','.'};
int n;
string s;
vector<string> all_pos[3];
void generate(int level, map<char,int> mp){
    if(level==n){
        for(int i=0;i<s.length();i++){
            if(s[i]!='.'){
                all_pos[s[i]-'A'].push_back(s);
                break;
            }
        }
        return;
    }
    for(auto v:mp){
        if(v.second>0){
            mp[v.first]--;
            s+=v.first;
            generate(level+1,mp);
            s.pop_back();
            mp[v.first]++;
        }
    }
}

string r,c;


bool check(string ch, string done){
    for(int pos=0;pos<n;pos++){
        if(ch[pos]!='.' && done[pos]=='0' && ch[pos]!=c[pos]){
            return false;
        }
    }
    return true;
}

string newdone(string done,string ch){
    for(int pos=0;pos<n;pos++){
        if(ch[pos]!='.'){
            done[pos]='1';
        }
    }
    return done;
}


bool is_valid(vector<string> sol){
    for(int j=0;j<n;j++){
        set<char> st;
        for(int i=0;i<n;i++){
            if(sol[i][j]!='.')st.insert(sol[i][j]);
        }
        if(st.size()!=3)return 0;
    }
    return 1;
}

vector<string> sol;
bool solution_found = false;
vector<string> final_solution;

string all_done,none_done;

void rec(int level, string done){
    if(level==n){
        if(done==all_done && is_valid(sol)){
            solution_found = true;
            final_solution=sol;
        }
        return;
    }
    
    int firstch = r[level]-'A';
    for(auto ch:all_pos[firstch]){
        if(solution_found)break;
        if(check(ch,done)){
            sol.push_back(ch);
            rec(level+1, newdone(done,ch));
            sol.pop_back();
        }
    }
}

int main(){
    
    cin>>n;
    cin>>r>>c;
    
    map<char,int> mp;
    for(int i=0;i<3;i++){
        mp[pos[i]]=1;
    }
    mp['.']=n-3;
    
    generate(0,mp);
    for(int i=0;i<n;i++){
        all_done +='1';
        none_done += '0';
    }
    
    rec(0,none_done);
    
    if(solution_found){
        cout<<"Yes\n";
        for(auto v:final_solution){
            cout<<v<<endl;
        }
    }else{
        cout<<"No\n";
    }
}