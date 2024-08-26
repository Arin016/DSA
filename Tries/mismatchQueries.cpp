#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

struct Node {
    int endcnt;
    int child[26];
    Node() {
        endcnt = 0;
        memset(child, -1, sizeof(child));
    }
};

struct trie {
    vector<Node> nodes;
    trie() {
        nodes.push_back(Node());
    }

    void insert(string s) {
        int curnodeidx = 0;
        for (int i = 0; i < s.length(); i++) {
            if (nodes[curnodeidx].child[s[i] - 'a'] == -1) {
                nodes.push_back(Node());
                nodes[curnodeidx].child[s[i] - 'a'] = nodes.size() - 1;
            }
            curnodeidx = nodes[curnodeidx].child[s[i] - 'a'];
        }
        nodes[curnodeidx].endcnt++;
    }

    void dfs(int nodeidx, int k, string curstring, string& squery) {
        if (k < 0) return;
        if (nodes[nodeidx].endcnt != 0 and curstring.size()==squery.size()) {
            cout << curstring << endl;
        }
        for (int i = 0; i < 26; i++) {
            if (nodes[nodeidx].child[i] != -1) {
                int childnodeidx = nodes[nodeidx].child[i];
                int new_k = k - ((squery[curstring.size()] - 'a') != i);  
                curstring += char('a' + i);
                dfs(childnodeidx, new_k, curstring, squery);
                curstring.pop_back();  
            }
        }
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    trie t;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        t.insert(x);
    }
    while (q--) {
        string x;
        int k;
        cin >> x >> k;
        t.dfs(0, k, "", x);  
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
