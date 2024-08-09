#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    // WRONGGG AND SENSELESS
    // for(int mask=0;mask<(1<<n);mask++){
    //     for(int submask=mask;submask>0;submask&=(submask-1)){
    //         //keeps on removing ones from behind
    //     }
    // }
    
    for(int mask=0;mask<(1<<n);mask++){
        for(int submask=mask;submask>0;submask=mask&(submask-1)){
            //toggles ones from behind one after the other 
        }
    }
}