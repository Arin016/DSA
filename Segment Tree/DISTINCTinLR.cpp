//convert the given array to an array that stores the index of last occurance of that value
//then number of disticnt elements in the range l...r would be 
//number of elements <=l-1 in range l...r

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;


int n,q;
int arr[200200];
vector<pair<int,int>> vals;


int t[400400];

void build(int index, int l, int r){
    if(l==r){
        t[index] = 0;
    }

    int mid = (l+r)/2;
    build(2*index,l,mid);
    build(2*index+1,mid+1,r);

    t[index] = t[2*index]+t[2*index+1];
}

void update(int index, int l, int r, int pos, int  val){
    if(pos<l || pos>r){
        return;
    }

    if(l==r){
        t[index] = val;
        return;
    }

    int mid = (l+r)/2;
    update(2*index,l,mid,pos,val);
    update(2*index+1,mid+1,r,pos,val);

    t[index] = t[2*index]+t[2*index+1];
}

int query(int index, int l, int r, int st, int en){
    if(st>r || en<l){
        return 0;
    }

    if(st<=l && r<=en){
        return t[index];
    }

    int mid = (l+r)/2;

    return query(2*index,l,mid,st,en)+query(2*index+1,mid+1,r,st,en);
}

void solve(){
   cin>>n>>q;
   map<int,int> mp;
   for(int i=0;i<n;i++){
    cin>>arr[i];
    if(mp.find(arr[i])==mp.end()){
        vals.push_back({-1,i});
        mp[arr[i]] = i;
    }else{
        vals.push_back({mp[arr[i]],i});
        mp[arr[i]]= i;
    }
   }

   sort(vals.begin(),vals.end());
    vector<pair<pair<int,int>,pair<int,int>>> queries;

    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        l--,r--;
        queries.push_back({{l-1,i},{l,r}});
    }
    
    sort(queries.begin(),queries.end());
    int ans[q];
    build(1,0,n-1);
    int pos = 0;
    for(auto v:queries){
        while(pos<n && vals[pos].F<=v.F.F){
            update(1,0,n-1,vals[pos].S,1);
            pos++;
        }
        ans[v.F.S] = query(1,0,n-1,v.S.F,v.S.S);
    }

    for(int i=0;i<q;i++){
        cout<<ans[i]<<endl;
    }

    
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}