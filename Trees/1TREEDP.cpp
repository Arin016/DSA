#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

//1 : In Out dp
//2 : ancestral path property dp
//3 : knapsack dp

//dp(node, ...... )

// return a vector where ans[i] tells if rooted at i whats the height?
//sibling = parents other child except node

//indp(node) = max(1+indp(child))

//outdp(node) = max(1+outdp(parent), max(2+indp(sibling)))

//rather than iterating over all siblings
//for each parent store firstmax and secondmax of indp amongst all child of a parent 
//why?? because iterating over all siblings and finding max indp would be O(n^2)

//ans = max(indp(node), outdp(node))

int indp[1000100];
int outdp[1000100];
int ans[1000100];
vector<int> g[1000100];

void indfs(int node, int par){
    //initialise the value as if node is a leaf
    indp[node] = 0; //thats the max depth amongst all its child :P, lMAO
    for(auto x:g[node]){
        if(x!=par){
            indfs(x, node);
            indp[node] = max(indp[node], 1+indp[x]);
        }
    }
}

void outdfs(int node, int par, int outval){
    outdp[node] = outval;
    int max1 = -1, max2 = -1;
    for(auto x:g[node]){
        if(x!=par){
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
        if(x!=par){
            if(indp[x]==max1){
                //outdp(node==x) = max(1+outdp(parent==node), {max(2+indp(sibling))}-->either of max1/2)
                outdfs(x, node, max(1+outdp[node], 2+max2));
            }
            else{
                outdfs(x, node, max(1+outdp[node], 2+max1));
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
    outdfs(1, 0, 0); //passing outval as 0 because root doesnt have parent nor siblings
    for(int i=1;i<=n;i++){
        cout<<max(indp[i],outdp[i])<<endl;
    } 
    //queries of for every number give the max or min except for that number from the set, maintain first and second maxi or mini accordingly
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
