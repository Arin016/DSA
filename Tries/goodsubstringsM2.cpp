#include <bits/stdc++.h>
using namespace std;


string s, h;
int k;

struct Node {
    int badcnt;
    int child[26];
    Node(int bc = 0) {
        badcnt = bc;
        memset(child, -1, sizeof(child));
    }
};

struct Trie {
    vector<Node> nodes;

    Trie() {
        nodes.clear();
        //pushing the root node, fill for root if req
        nodes.push_back(Node());
    }

    void insert(const string &s) {
        int curnodeidx = 0; //starting from the root, remember parent node is numbered as 0
        int badChars = 0;

        for (auto c : s) {
            int idx = c - 'a';

            // Count bad characters
            if (h[idx] == '0') badChars++;

            if (nodes[curnodeidx].child[idx] == -1) {
                nodes.push_back(Node(badChars)); //change the new node
                nodes[curnodeidx].child[idx] = nodes.size() - 1; //storing address of baccha in parent
            }
            //process this node for one last time before going to baccha node
            //prefixcnt++;
            curnodeidx = nodes[curnodeidx].child[idx]; //setting the curr node idx to baccha's idx
        }
        //end of the string
        //endcnt++;
    }

    int dfs(int nodeidx){
        int ans = 0;
        if(nodes[nodeidx].badcnt<=k)ans++;
        for(int i=0;i<26;i++){
            if(nodes[nodeidx].child[i]!=-1){
                int childnodeidx = nodes[nodeidx].child[i];
                ans+=dfs(childnodeidx);
            }
        }
        return ans;
    }

    int getcnt(){
        return dfs(0);
    }
};

void solve() {
    cin >> s >> h >> k;
    Trie t;
    for (int i = 0; i < s.length(); i++) {
        t.insert(s.substr(i));
    }
    cout<<t.getcnt()-1<<endl; //-1 to take off the root node!
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}