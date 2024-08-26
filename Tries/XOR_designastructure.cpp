#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


struct Node {
    int cnt; //number of numbers that are going through this node
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
        //incrementing in the end too when we reach the last node
        // because the value of cnt for last node wasnt incremented in the looping
    }

    void remove(int x) {
        int curnodeidx = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if(nodes[curnodeidx].cnt>0)nodes[curnodeidx].cnt--;
            if (nodes[curnodeidx].child[bit] != -1) {
                if (nodes[curnodeidx].cnt == 0) { //theres no number in the trie passing through this node 
                    nodes[curnodeidx].child[bit] = -1;
                    break;
                }
            }
            curnodeidx = nodes[curnodeidx].child[bit];
        }
        if(nodes[curnodeidx].cnt>0)nodes[curnodeidx].cnt--;
    }

    //build and give the xor value itself!!!

    /*
    Ensuring a Valid Path: The Trie can have paths that no longer correspond to any numbers because of deletions. 
    The cnt field in each node represents the number of numbers passing through that node. 
    Therefore, before choosing a particular path in the Trie (i.e., nodes[curnodeidx].child[oppositeBit]), 
    you must ensure that this path is valid, meaning there are still numbers passing through it (nodes[childnodeidx].cnt > 0).

    Avoiding Dead Paths: If you don't check nodes[childnodeidx].cnt > 0, you might follow a path that doesn't lead to any number, 
    resulting in an incorrect XOR computation. This could happen especially after numbers have been removed from the Trie, 
    leading to some nodes having cnt = 0.*/

    int query(int x) {
        int ans = 0;
        int curnodeidx = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            int oppositeBit = bit ^ 1;
            int childnodeidx = nodes[curnodeidx].child[oppositeBit];
            if (nodes[curnodeidx].child[oppositeBit] != -1 and nodes[childnodeidx].cnt>0) {
                ans |= (1 << i);
                curnodeidx = childnodeidx;
            } else {
                curnodeidx = nodes[curnodeidx].child[bit];
            }
        }
        return ans;
    }
};



void solve(){
    int q;
    cin >> q;
    Trie tt;
    tt.insert(0);
    while(q--){
            char ch;
            cin >> ch;
            int x;
            cin >> x;
            if(ch == '+'){
                tt.insert(x);
            }else if(ch == '-'){
                tt.remove(x);
            }else{
                cout<<tt.query(x)<<endl;
            }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
