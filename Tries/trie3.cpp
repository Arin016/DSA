#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

struct Node{
    int endcnt;
    int prefixcnt;
    vector<int> allmatchtillnow;
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

    void insert(string s, int stringidx){
        int curnodeidx = 0; //startingt from the root, remember parent node is numbered as 0
        for(int i=0;i<s.length();i++){
            if(nodes[curnodeidx].child[s[i]-'a']==-1){
                Node newnode;
                //change the new node
                nodes.push_back(newnode);
                nodes[curnodeidx].child[s[i]-'a'] = nodes.size()-1; //storing address of baccha in parent
            }
            //process this node before going to child
            nodes[curnodeidx].prefixcnt++;
            if(nodes[curnodeidx].allmatchtillnow.size()<3)nodes[curnodeidx].allmatchtillnow.push_back(stringidx);
            curnodeidx = nodes[curnodeidx].child[s[i]-'a']; //curnodeidx is tracking the node number you are at in the nodes vector
        }
        //end of the string
        nodes[curnodeidx].endcnt++;
        if(nodes[curnodeidx].allmatchtillnow.size()<3)nodes[curnodeidx].allmatchtillnow.push_back(stringidx);
    }


    //deleting from a trie reverse the insertion process ++ with -- and pushback with popback
    //the structure shouldnt change


    // void dfs(int nodeidx, string& curstring){
    //     if(nodes[nodeidx].endcnt>0){
    //         cout<<curstring<<" ";
    //     }
    //     for(int i=0;i<26;i++){
    //         if(nodes[nodeidx].child[i]!=-1){
    //             curstring+=(char)('a'+ i);
    //             dfs(nodes[nodeidx].child[i], curstring); //nodes[nodeidx].child[i] stores next nodes number
    //             curstring.pop_back();
    //         }
    //     }
    // }

    void query(string s, vector<string> allstrings){
        //this is the only way you iterate in a trie
        int curnodeidx = 0;
        for(int i=0;i<s.length();i++){
            if(nodes[curnodeidx].child[s[i]-'a']==-1){
                //such a branching from root node doesnt exist
                cout<<0<<endl;
                return;
            }
            curnodeidx = nodes[curnodeidx].child[s[i]-'a'];
        }

        // curnodeidx points at the node which has the string equal to s

        cout<<nodes[curnodeidx].endcnt+nodes[curnodeidx].prefixcnt<<endl;
        for(auto x:nodes[curnodeidx].allmatchtillnow){
            cout<<allstrings[x]<<" ";
        }
        cout<<endl;
        // dfs(curnodeidx, s); //mo wale trie node pe gaya uska node index aur s = mo rakh kar dfs marr raha
    }
};


void solve(){
    int n;
    cin>>n;
    vector<string> allstrings;
    trie t;
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        allstrings.push_back(x);
    }
    sort(allstrings.begin(), allstrings.end());
    for(int i=0;i<n;i++){
        t.insert(allstrings[i], i);
    }
    int q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        t.query(s, allstrings);
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
