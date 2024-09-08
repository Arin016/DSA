#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

//binary lifting:
//you need to answer queries of the form: ? x k
//what is the kth element after the xth element?

//Next(x, i) --> stores whats the 2^ith element after the xth element

//breaking the k ---> get into binary representation of k and jump in powers of k
//lets say k = 13
// k = (1101)2
//jumps would be of 2^i and thed be (start)--8-->(x1)--4-->(x2)--1-->(end)
//for start we know 8th (2^3) element and from that element (x1) we know the 4th (2^2) element and blah blah blah!!

//building the structure:
//Next(x, i) = Next(Next(x, i-1), i-1)
//any jump of 2^i can be broken down into 2^i/2 and 2^i/2 i.e. 2^(i-1) and 2^(i-1)
//finding the kth after xth:
// int x; //given
// for(int i=19;i>=0;i--){ //iterating on k's bits
//     if((k>>i)&1){
//         x = Next(x, i);
//     }
// }

const int MAXN = 1e5 + 5;
const int LOG = 20;

int Next[MAXN][LOG]; // Next[x][i] stores the 2^i-th element after x

void solve(){
    int n, q;
    cin >> n >> q;
    
    // Input the Next element directly
    for (int i = 1; i <= n; i++) {
        cin >> Next[i][0]; // directly store the Next element (2^0-th element)
    }
    
    // Building the structure for binary lifting
    for (int i = 1; i < LOG; i++) {
        for (int x = 1; x <= n; x++) {
            Next[x][i] = Next[Next[x][i-1]][i-1];
        }
    }

    // Answering the queries
    while (q--) {
        int x, k;
        cin >> x >> k;

        // Finding the kth element after x
        for (int i = LOG-1; i >= 0; i--) {
            if ((k >> i) & 1) {
                x = Next[x][i];
            }
        }
        
        cout << x << "\n";
    }
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
    return 0;
}
