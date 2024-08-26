#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

struct Node{
    int endcnt;
    int prefixcnt;
    int child[26];
    Node(){
        endcnt = 0;
        prefixcnt = 0;
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
        int curnodeidx = 0; //startingt from the root, remember parent node is numbered as 0
        for(int i=0;i<s.length();i++){
            if(nodes[curnodeidx].child[s[i]-'a']==-1){
                Node newnode;
                //change the new node
                nodes.push_back(newnode);
                nodes[curnodeidx].child[s[i]-'a'] = nodes.size()-1; //which node was its parent
            }
            //process this node before going to child
            nodes[curnodeidx].prefixcnt++;
            curnodeidx = nodes[curnodeidx].child[s[i]-'a']; //curnodeidx is tracking the node number you are at in the nodes vector
        }
        //end of the string
        nodes[curnodeidx].endcnt++;
    }

    void query(string s){
        //this is the only way you iterate in a trie
        int curnodeidx = 0;
        for(int i=0;i<s.length();i++){
            if(nodes[curnodeidx].child[s[i]-'a']==-1){
                cout<<0<<endl;
                return;
            }
            curnodeidx = nodes[curnodeidx].child[s[i]-'a'];
        }
        cout<<nodes[curnodeidx].endcnt<<" "<<nodes[curnodeidx].prefixcnt<<endl;
    }

    int getnodecount(){
        return nodes.size(); //including root
    }
};


void solve(){
    int n;
    cin>>n;
    trie t;
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        t.insert(x);
    }
    int q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        t.query(s);
    }

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
