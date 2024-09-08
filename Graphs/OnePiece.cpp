//0-1 BFS
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define int long long

using state = pair<int, int>;
int n,m;
vector<vector<int>> arr;


bool check(state x){
	if(x.F<0||x.F>=n||x.S<0||x.S>=m)return false;
	else return true;
}

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

vector<pair<state, int>> neighbours(state x){
	vector<pair<state, int>> ans;
	for(int k=0;k<4;k++){
		int nx = x.F+dx[k];
		int ny = x.S+dy[k];
		if(check(make_pair(nx, ny))){
			if(arr[x.F][x.S]==1){
				if(dx[k]==0&&dy[k]==1){
					ans.push_back({{nx, ny}, 0});
				}
				else ans.push_back({{nx, ny}, 1});
			}
			else if(arr[x.F][x.S]==2){
				if(dx[k]==0&&dy[k]==-1){
					ans.push_back({{nx, ny}, 0});
				}
				else ans.push_back({{nx, ny}, 1});
			}
			else if(arr[x.F][x.S]==3){
				if(dx[k]==1&&dy[k]==0){
					ans.push_back({{nx, ny}, 0});
				}
				else ans.push_back({{nx, ny}, 1});
			}
			else if(arr[x.F][x.S]==4){
				if(dx[k]==-1&&dy[k]==0){
					ans.push_back({{nx, ny}, 0});
				}
				else ans.push_back({{nx, ny}, 1});
			}
			
			}
		}
		
	
	return ans;
}

void printerpr(vector<pair<state, int>> xx){
	for(auto v:xx){
		cout<<"{"<<v.F.F<<", "<<v.F.S<<"}"<<" "<<v.S<<endl; 
	}
}

void printer(vector<vector<int>> xx){
    for(auto v:xx){
        for(auto u:v){
            cout<<u<<"\t";
        }
        cout<<"\n";
    }   
    cout<<endl;
}

vector<vector<int>> dis;
void bfs01(state st){
	dis.assign(n, vector<int>(m, INF));
	deque<state> dq;
	dis[st.F][st.S]=0;
	dq.push_back(st);
	while(!dq.empty()){
		state cur = dq.front();
		dq.pop_front();
		for(auto v:neighbours(cur)){
			state neigh = v.F; //try writing child from now on, better clarity maybe
			int weight = v.S;
			if(dis[neigh.F][neigh.S]>dis[cur.F][cur.S]+weight){
				dis[neigh.F][neigh.S]=dis[cur.F][cur.S]+weight;
				if(weight==0){
					dq.push_front(neigh);
				}
				else{
					dq.push_back(neigh);
				}
			}
		}
	}
}

signed main(){
	cin>>n>>m;
    arr.assign(n, vector<int>(m, 0));
    for(int i=0;i<n;i++){
       	for(int j=0;j<m;j++){
       		cin>>arr[i][j];
       	}
    }
    // printerpr(neighbours({1, 1}));
    bfs01({0, 0});
    // printer(dis);
    state en = {n-1, m-1};
    cout<<dis[en.F][en.S]<<endl;
}