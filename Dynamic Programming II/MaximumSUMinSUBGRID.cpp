#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

int n, m;
vector<vector<int>> a;
vector<vector<int>> prow, pcol;

//maximum subarray sum ke andar iterate karke nikalna hai har i ke liye kahan max aara, yaad rakh ye baat!

int PCOL(int i, int j, int k){
    return (i-1 >= 0) ? pcol[k][j] - pcol[i-1][j] : pcol[k][j];
}

int PROW(int i, int j, int k){
    return (j-1 >= 0) ? prow[i][k] - prow[i][j-1] : prow[i][k];
}

void solve(){
    cin >> n >> m;
    a.assign(n+1, vector<int>(m+1, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    prow.assign(n+1, vector<int>(m+1, 0));
    pcol.assign(n+1, vector<int>(m+1, 0));

    //prow computation
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            prow[i][j] = a[i][j];
            if(j) prow[i][j] += prow[i][j-1];
        }
    }

    //pcol computation
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            pcol[i][j] = a[i][j];
            if(i) pcol[i][j] += pcol[i-1][j];
        }
    }

    int ans = -1e18;

    if(n <= m){
        for(int i = 0; i < n; i++){ // choosing start stick
            int temp = -1e18;
            for(int k = i; k < n; k++){ // choosing end stick
                // putting kadane on the strip!
                int dp[m]; // start new or continue!
                //dp[i] represents the maximum subarray sum ending at index i
                for(int j = 0; j < m; j++){
                    if(j == 0){
                        dp[j] = PCOL(i, j, k);
                    }
                    else{
                        dp[j] = max(dp[j-1] + PCOL(i, j, k), PCOL(i, j, k));
                    }
                    temp = max(temp, dp[j]);
                }
            }
            ans = max(ans, temp);
        }
    }
    else{
        for(int j = 0; j < m; j++){ // choosing start stick
            int temp = -1e18;
            for(int k = j; k < m; k++){ // choosing end stick
                // putting kadane on the strip!
                int dp[n]; // start new or continue!
                //dp[i] represents the maximum subarray sum ending at index i
                for(int i = 0; i < n; i++){
                    if(i == 0){
                        dp[i] = PROW(i, j, k);
                    }
                    else{
                        dp[i] = max(dp[i-1] + PROW(i, j, k), PROW(i, j, k));
                    }
                    temp = max(temp, dp[i]);
                }
            }
            ans = max(ans, temp);
        }
    }

    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
