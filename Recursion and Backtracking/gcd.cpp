#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int gcd(int a, int b){
    if(b==0)return a;
    return gcd(b, a%b);
}


//REMEMBER::O(2^n-1)
void towerofhanoi(int x, int sc, int tt, int aux) {
    if (x == 0) return;  // Base case: if there are no disks to move, return.
    towerofhanoi(x-1, sc, aux, tt);  // Move (x-1) disks from source to auxiliary.
    cout << "move disc " << x << " from " << sc << " to " << tt << endl;  // Move the largest disk to the target.
    towerofhanoi(x-1, aux, tt, sc);  // Move the (x-1) disks from auxiliary to target.
}


//backtracking = LCCM
//recursion = BRAINS!

//i had to solve reccurance and figure out 2^n - 1 moves in each branch
void kthmove(int disc, int start, int target, int aux, int k) {
    if (disc == 0) return;

    // Move (disc-1) from start to aux using target, # of moves = (2^(disc-1))-1
    if (k <= (1 << (disc - 1)) - 1) {
        kthmove(disc - 1, start, aux, target, k);
    }
    // Move the disc from start to target, # of moves = 1
    else if (k == (1 << (disc - 1))) {
        cout << "The kth move is: move disc " << disc << " from " << start << " to " << target << endl;
    }
    // Move the (disc-1) from aux to target using start, # of moves = (2^(disc-1))-1
    else {
        kthmove(disc - 1, aux, target, start, k - (1 << (disc - 1)));
    }
}


void solve(){

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
