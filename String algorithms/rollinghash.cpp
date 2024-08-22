#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

//look at the implementation
//s0
//s0p+s1
//s0p^2+s1p+s2
//.......
int quickhash(string s, int p, int mod){
    int ans = (s[0]-'a'+1);
    for(int i=1;i<s.length();i++){
        ans = (ans*p+(s[i]-'a'+1))%mod;
    }
    return ans;
}



struct hasher{
    int sz, mod, p;
    vector<int> fhash;
    vector<int> ppowerk;
    void init(string s, int _p, int _mod){
        mod = _mod;
        p = _p;
        sz = s.length();
        fhash.resize(sz);
        fhash[0] = (s[0]-'a'+1);
        ppowerk.resize(sz);
        ppowerk[0] = 1;
        for(int i=1;i<s.length();i++){
            fhash[i] = (fhash[i-1]*p+(s[i]-'a'+1))%mod;
            ppowerk[i] = (ppowerk[i-1]*p)%mod;
        }

    }

    int getfhash(int l, int r){
        //s[l...r]
        if(l==0)return fhash[r];
        return ((fhash[r]-(fhash[l-1]*ppowerk[r-l+1])%mod)+mod)%mod;
    }
};

void solve(){
    string s;
    cin>>s;
    hasher shash;
    shash.init(s, 31, 1e9+7);
    int n = s.length();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cout<<shash.getfhash(i, j)<<endl;
        }
    }


    //application1:
    //longest common substring in s1 and s2
    //m1:dp
    //m2:
    //Binary search on length
    //if x length is possible then x-1, x-2 .. is also possible
    //check(s1, s2, x)
    //is x length substring fhash commonly oresent in both s1 and s2
    //run loops in both s1 and s2 and store all hashes for x length substrings starting at i and maintain a map
     
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
