#include <bits/stdc++.h>
using namespace std;

struct Node {
    int cnt;
    int child[2];
    Node() {
        cnt = 0;
        memset(child, -1, sizeof(child));
    }
};

struct Trie {
    vector<Node> nodes;
    Trie() {
        nodes.push_back(Node());
    }

    void insert(int x) {
        int curnodeidx = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            nodes[curnodeidx].cnt++;
            if (nodes[curnodeidx].child[bit] == -1) {
                nodes.push_back(Node());
                nodes[curnodeidx].child[bit] = nodes.size() - 1;
            }
            curnodeidx = nodes[curnodeidx].child[bit];
        }
        nodes[curnodeidx].cnt++;
    }
    //build and give the xor value itself!!!
    int query(int x) {
        int ans = 0;
        int curnodeidx = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            int oppositeBit = bit ^ 1;
            int childnodeidx = nodes[curnodeidx].child[oppositeBit];
            if (nodes[curnodeidx].child[oppositeBit] != -1 and nodes[childnodeidx].cnt>0) {
                ans |= (1 << i);
                curnodeidx = nodes[curnodeidx].child[oppositeBit];
            } else {
                curnodeidx = nodes[curnodeidx].child[bit];
            }
        }
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if(i)a[i]^=a[i-1];
    }

    Trie t;
    t.insert(0); // Insert 0 to handle subarrays starting from the first element
    int maxi = a[0];
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, t.query(a[i]));
        t.insert(a[i]);
    }
    cout << maxi << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
