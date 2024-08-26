#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

//https://maang.in/playlists/Day-18-More-Bit-Trie-Ideas-3834?resourceUrl=cs99-cp559-pl3834-rs7773&returnUrl=/courses/Premium-Day-Wise-Course-99?tab=chapters
//rewatching is worth it

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
    //(x^y<=k) count such number of x
    //to understand the direction in which to move make a y vs k 2 x 2 matrix 
    int query(int y, int k) {
        int ans = 0;
        int curnodeidx = 0;
        for (int i = 31; i >= 0; i--) {
            int bitb = (y >> i) & 1;
            int bitc = (k >> i) & 1;
            if(bitb==0 and bitc==0 ){
                //bita^0<=0
                //i have to choose bita to be 0
                if(nodes[curnodeidx].child[0]!=-1)curnodeidx = nodes[curnodeidx].child[0];
            }
            else if(bitb==0 and bitc==1){
                //bita^0<=1
                //all the numbers for which bita is 0 are for sure answers and then for bita=1 check furthur
                int childnodeidx = nodes[curnodeidx].child[0];
                if (childnodeidx != -1) ans += nodes[childnodeidx].cnt;
                if(nodes[curnodeidx].child[1]!=-1)curnodeidx = nodes[curnodeidx].child[1];
            }
            else if(bitb==1 and bitc==0){
                //bita^1<=0
                //ill have to choose bita to be 1
                if(nodes[curnodeidx].child[1]!=-1)curnodeidx = nodes[curnodeidx].child[1];
            }
            else if(bitb==1 and bitc==1){
                //bita^1<=1
                //all the numbers for which bita is 1 are for sure answers and then for bita=0 check furthur
                int childnodeidx = nodes[curnodeidx].child[1];
                if (childnodeidx != -1) ans += nodes[childnodeidx].cnt;
                if(nodes[curnodeidx].child[0]!=-1)curnodeidx = nodes[curnodeidx].child[0];
            }
        }
        return ans;
    }
};



void solve(){
    
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
