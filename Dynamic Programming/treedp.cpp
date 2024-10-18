#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> g[100100];
int ans[100100];
int indp[100100];
int outdp[100100];

//indp[node] = max depth within subtree of node
void indfs(int node, int p){
    //leaf assume kar ke set kar!
    indp[node] = 0;
    for(auto x:g[node]){
        if(x!=p){
            indfs(x, node);
            //dp compute kar!
            indp[node] = max(indp[x]+1, indp[node]);
        }
    }
}

//outdp[node] = max depth outside subtree of node
void outdfs(int node, int p, int outval){
    //root node assume karke initialise kar!
    outdp[node] = outval;
    int max1 = -1, max2 = -1;
    for(auto x:g[node]){
        if(x!=p){
            if(indp[x]>max1){
                max2 = max1;
                max1 = indp[x];
            }
            else if(indp[x]>max2){
                max2 = indp[x];
            }
        }
    }


    for(auto x:g[node]){
        if(x!=p){
            if(indp[x]==max1){
                outdfs(x, node,max(max2+2, outdp[node]+1));
            }
            else{
                outdfs(x, node, max(max1+2, outdp[node]+1));
            }
        }
    }
}
void solve(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    indfs(1, 0);
    outdfs(1, 0, 0);
    // ans_dfs();
    for(int i=1;i<=n;i++){
        cout<<indp[i]+outdp[i]<<endl;
    }   
}

int main(){
    solve();
}