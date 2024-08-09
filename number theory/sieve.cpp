#include<bits/stdc++.h>
using namespace std;

//primes in [1......1e7]
bool is_prime[1000100];
void sieveoferatosthenes(){
    for(int i=2;i<1000100;i++)is_prime[i] = 1;
    for(int i=2;i<1000100;i++){
        if(is_prime[i]){
            for(long long j=i+i;j<1000100;j+=i){ //optimisation: i+i --> i*i
                is_prime[j] = 0;
            }
        }
    }

    // n/2 + n/3 + n/5 + n/7 ..... -->O(nloglogn)
    // n/1 + n/2 + n/3 + n/4 ..... -->O(nlogn)
}

void solve(){

}

int main(){
    solve();
}