#include <bits/stdc++.h>
using namespace std;


//MCCC using #define int long long was throwing RE!!!!!!!!!!**********

string s, h;
int k;

struct Node {
    int child[26];
    Node() {
        memset(child, -1, sizeof(child));
    }
};

struct Trie {
    vector<Node> nodes;

    Trie() {
        nodes.clear();
        nodes.push_back(Node());
    }

    void insert(const string &s) {
        int curnodeidx = 0;
        int badChars = 0;

        for (int i=0;i<s.length();i++) {
            int idx = s[i] - 'a';

            // Count bad characters
            if (h[idx] == '0') badChars++;
            if(badChars>k)break;

            if (nodes[curnodeidx].child[idx] == -1) {
                nodes.push_back(Node());
                nodes[curnodeidx].child[idx] = nodes.size() - 1;
            }

            curnodeidx = nodes[curnodeidx].child[idx];
        }
    }

    int getnodescnt(){
        return nodes.size();
    }
};

void solve() {
    cin >> s >> h >> k;
    Trie t;
    for (int i = 0; i < s.length(); i++) {
        t.insert(s.substr(i));
    }
    cout<<t.getnodescnt()-1<<endl;
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