#include<bits/stdc++.h>
using namespace std;
#define int long long

struct Node{
    int endcnt;
    int prefixcnt;
    int child[2];
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
        nodes.push_back(Node());
    }

    void insert(int n){
        int curnodeidx = 0;
        for(int i = 4; i >= 0; i--){
            int bit = (n >> i) & 1;
            if(nodes[curnodeidx].child[bit] == -1){
                nodes.push_back(Node());
                nodes[curnodeidx].child[bit] = nodes.size() - 1;
            }
            nodes[curnodeidx].prefixcnt++;
            curnodeidx = nodes[curnodeidx].child[bit];
        }
        nodes[curnodeidx].endcnt++;
    }
};

void solve(){
    // Implementation of solving logic
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
