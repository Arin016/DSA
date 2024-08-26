#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
//why isnt everythnig a solution
//generator and checker
//generating is harder
//choose one constraint as generator and other as checker


//generate all permutations of 10 digits and map them to a b c d e f g h i j
//check if fghij divides abcde 

void option_one(int n){
    //generate using permutation, check equation
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int cnt = 0;
    do{
        int abcde = arr[0]*10000 +arr[1]*1000 + arr[2]*100 + arr[3]*10 + arr[4];
        int fghij = arr[5]*10000 +arr[6]*1000 + arr[7]*100 + arr[8]*10 + arr[9];
        if(abcde%fghij==0){
            if(abcde/fghij==n){
                cout<<abcde<<" "<<fghij<<endl;
                cnt++;
            }
        }
    }while(next_permutation(arr,arr+10));
    cout<<cnt<<endl;
}

void option_two(int n){
    //generate using equation, check permutaion

    //range of abcde = (01234,98765);
    //range of fghij = (01234,98765/n);
    int cnt = 0;
    for(int fghij = 01234;fghij<=(98765/n);fghij++){
        int abcde = fghij*n;

        //check all are distinct
        set<int> st;
        int temp = abcde;
        for(int i=0;i<5;i++){
            st.insert(temp%10);
            temp = temp/10;
        }

        temp = fghij;
        for(int i=0;i<5;i++){
            st.insert(temp%10);
            temp = temp/10;
        }


        if(st.size()==10){
            cout<<abcde<<" "<<fghij<<endl;
            cnt++;
        }
    }
    cout<<cnt<<endl;
}


void solve(){
   int n;
   cin>>n;
    option_one(n);
    option_two(n);

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
