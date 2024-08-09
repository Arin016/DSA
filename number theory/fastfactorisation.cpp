#include <bits/stdc++.h>
using namespace std;


int sp[1000100]; //smallest prime --> sp
void fastfact(){
    for(int i=2;i<1000100;i++)sp[i] = i;
    for(int i=2;i*i<1000100;i++){
        if(sp[i]==i){
            for(int j=2*i;j<1000100;j+=i){
                if(sp[j]==j)sp[j] = i;
            }
        }
    }
}

//no of prime factors of a number is of the order logn

vector<int> primefact(int x){
    vector<int> ans;
    while(x>1){
        ans.push_back(sp[x]);
        x/=sp[x];
    }
    return ans;
}

void solve(){
    //number of divisors --> p1^a1*p2^a2*p3^a3..... = (1+a1)c1*(1+a2)c1*....*(1+an)c1
    //the choices where for each ai you have ai+1 choices the +1 being for not picking any number of pi's
    //sum of divisors --> ((p1^(a1+1)-1)/(p1-1))*((p2^(a2+1)-1)/(p2-1))*.....((pn^(an+1)-1)/(pn-1))
    //incluion exclusion principle:
    //x-(x/p1)-(x/p2)+(x/(p1*p2))
    //total nos - no of multiples of p1 - no of multiples of p2 + no of multiples of both p1 and p2
    //-->phi(x) = x*(1-(1/p1))*(1-(1/p2))..... //number of coprimes of x in [1....x] where pi are the prime factors
    //we can extend the same for a bigger case
    

    //product of divisors:
    // productof(pi^(((a1*(ai+1))/2)*((# of divisors)/(ai+1))))
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    solve();
}