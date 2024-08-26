#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, maxlen, q;
vector<string> allstrings;

struct Node{
    vector<int> indices;
    int child[26];
    Node(){
        memset(child, -1, sizeof(child));
    }
};

struct trie{
    vector<Node> nodes;
    trie(){
        nodes.push_back(Node());
    }

    void insert(string s, int stringidx){
        int curnodeidx = 0;
        for(int i = 0; i < s.length(); i++){
            if(nodes[curnodeidx].child[s[i]-'a'] == -1){
                nodes.push_back(Node());
                nodes[curnodeidx].child[s[i]-'a'] = nodes.size() - 1;
            }
            nodes[curnodeidx].indices.push_back(stringidx);
            curnodeidx = nodes[curnodeidx].child[s[i]-'a'];
        }
        nodes[curnodeidx].indices.push_back(stringidx);
    }

    void query(string s, int k){
        int curnodeidx = 0;
        for(int i = 0; i < s.length(); i++){
            if(nodes[curnodeidx].child[s[i]-'a'] == -1){
                cout << endl;
                return; // Prefix doesn't exist
            }
            curnodeidx = nodes[curnodeidx].child[s[i]-'a'];
        }
        // curnodeidx points at the node which has the string equal to s
        for(int i = 0; i < min(k,(int)nodes[curnodeidx].indices.size()); i++){
            int idx = nodes[curnodeidx].indices[i];
            cout << allstrings[idx] << " ";
        }
        cout << endl;
    }
};

void solve(){
    cin >> n >> maxlen >> q;
    for(int i = 0; i < n; i++){
        int x;
        string temp;
        cin >> x >> temp;
        allstrings.push_back(temp);
    }
    sort(allstrings.begin(), allstrings.end());
    trie t;
    for(int i = 0; i < n; i++){
        t.insert(allstrings[i], i);
    }
    while(q--){
        int x, k;
        string squery;
        cin >> x >> squery >> k;
        for(int i=0;i<x;i++){
            t.query(squery.substr(0, i+1), k);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}
