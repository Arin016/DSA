#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


//in a trie the node represents a string and the edges carry the characters that were used to get to the subsequent nodes

struct Node{
    int child[26];
    Node(){
        memset(child, -1, sizeof(child));
    }
};

struct trie{
    vector<Node> nodes;
    trie(){
        nodes.clear();
        //pushing the root node, fill for root if req
        Node rootnode;
        nodes.push_back(rootnode);
    }

    void insert(string s){
        int curnodeidx = 0; //startingt from the root
        for(int i=0;i<s.length();i++){
            if(nodes[curnodeidx].child[s[i]-'a']==-1){
                Node newnode;
                //change the new node
                nodes.push_back(newnode);
                nodes[curnodeidx].child[s[i]-'a'] = nodes.size()-1; //which node was its parent, remember parent node is numbered as 0
            }
            curnodeidx = nodes[curnodeidx].child[s[i]-'a']; //curnodeidx is tracking the node number you are at in the nodes vector
        }
        //end of the string
    }

    int getnodecount(){
        return nodes.size(); //including root
    }
};


void solve(){
    string s;
    cin>>s;
    trie t;
    for(int i=0;i<s.length();i++){
        t.insert(s.substr(i));
    }
    cout<<t.getnodecount()-1<<endl;
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
