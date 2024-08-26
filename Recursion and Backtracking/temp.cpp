#include<bits/stdc++.h>
using namespace std;
#define int long long 

int n;
const int N=100;
vector<vector<int>>allsol;
vector<int>ans={1};

bool isPrime[N];
bool marked[N];
vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int solution_count=0;

void recur(int level,int prev){
    //base case 
    if(level==n){
        if(isPrime[1 + prev]){
            solution_count +=1;
        }
        return;
    }
    //recursion
    //choice 
    for(int i=2;i<=n;i++){
        if(!marked[i] && isPrime[i+prev]){
            marked[i]=true;
            recur(level+1,i);
            marked[i]=false;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    if(n%2) cout<<0<<"\n"; 
    else {
        marked[1]=true;
        memset(isPrime, false, sizeof(isPrime));
        
        for (int u : prime){
        isPrime[u] = true;
        }
        recur(1,1);
        cout<<solution_count<<"\n";}

}