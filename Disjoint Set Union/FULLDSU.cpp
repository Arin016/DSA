#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;


int n, m; //n=players, m=teams
//using rank and path compression is a choice the complexity would still remain logn if only one is used
vector<int> playerno;
struct dsu{
    int cmp;
    vector<int> size;
    vector<int> teampar;
    vector<int> teamsize; //extra!
    vector<map<int, int>> jerseynos; //extra!
    vector<int> player;

    void init(int n, int m){
        cmp = m;
        teampar.resize(m+1); //par
        size.resize(m+1); //size
        teamsize.resize(m+1); //EXTRA, to maintain cnt of players in a team
        jerseynos.resize(m+1); //EXTRA, to maintain (jerseyno, freq) of players in a team
        player.resize(n+1);
        for(int i=1;i<=m;i++){
            teampar[i] = i;
            teamsize[i] = 0;
            size[i] = 1;
        }
        for(int i=1;i<=n;i++){
            player[i] = -1;
        }
    }

    int find(int x){
        if(x==teampar[x])return x;
        else return teampar[x] = find(teampar[x]); //path compression
    }

    bool merge(int x, int y){
        int xL = find(x);
        int yL = find(y);
        if(xL == yL) return false;
        // rank compression
        if(size[xL] <= size[yL]){
            teampar[xL] = yL;
            size[yL] += size[xL];
            teamsize[yL]+=teamsize[xL];
            for(auto v:jerseynos[xL]){
                jerseynos[yL][v.first]+=v.second;
            }
            jerseynos[xL].clear();
        } else {
            teampar[yL] = xL;
            size[xL] += size[yL];
            teamsize[xL]+=teamsize[yL];
            for(auto v:jerseynos[yL]){
                jerseynos[xL][v.first]+=v.second;
            }
            jerseynos[yL].clear();
        }
        cmp--;
        return true;
    }

};

void solve(){
    cin>>n>>m;
    playerno.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>playerno[i];
    }
    int q;
    cin>>q;
    dsu d;
    d.init(n, m);
    //dsu is done for the m teams and below that there lies a layer of n players
    while(q--){
        int ch;
        cin>>ch;
        if(ch==1){
            int x, a; //add player x to team a
            cin>>x>>a;
            if(d.player[x]!=-1){ //player koi aur team mein hai ussse nikal pehle
                int xteam = d.find(d.player[x]);
                d.teamsize[xteam]--;
                d.jerseynos[xteam][playerno[x]]--;
                if(d.jerseynos[xteam][playerno[x]]==0){
                    d.jerseynos[xteam].erase(d.jerseynos[xteam][playerno[x]]);
                }
            }
            d.player[x] = a;
            int xteam = d.find(d.player[x]);
            d.teamsize[xteam]++;
            d.jerseynos[xteam][playerno[x]]++;
        }
        else if(ch==2){
            int a, b; //merge team a and b
            cin>>a>>b;
            d.merge(a, b);
        }
        else if(ch==3){
            int x, y; //check if x and y are in same team
            cin>>x>>y;
            int xteam = d.find(d.player[x]);
            int yteam = d.find(d.player[y]);
            if(xteam==yteam)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else if(ch==4){
            int x; //how many players in team that has player x?
            cin>>x;
            int xteam = d.find(d.player[x]);
            if(xteam==-1){ //not part of a team yet! 
                cout<<-1<<endl;
            }
            cout<<d.teamsize[xteam]<<endl;
        }
        else if(ch==5){
            int a; //find the number of distinct jersey no all players in the team a
            cin>>a;
            //cant use set becuase well have to remove and maintain distinct too as players can move around 
            //thus we use a map
            int xteam = d.find(a);
            if(xteam==-1){ //not part of a team yet! 
                cout<<-1<<endl;
            }
            cout<<d.jerseynos[xteam].size()<<endl;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
