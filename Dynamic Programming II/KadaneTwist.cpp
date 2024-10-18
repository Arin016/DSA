#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<int> arr[51];

struct max_sum_val{    
    int kadanes_ans;
    int best_prefix;
    int best_suffix;
    int total;

    void build(vector<int> arr){
        int n = arr.size();
        total = 0;
        for(int i = 0; i < n; i++)total += arr[i];

        best_prefix = arr[0];
        int temp_prefix = arr[0];
        for (int i = 1; i < n; i++){
            temp_prefix += arr[i];
            best_prefix = max(best_prefix, temp_prefix);
        }

        best_suffix = arr[n - 1];
        int temp_suffix = arr[n - 1];
        for (int i = n - 2; i >= 0; i--){
            temp_suffix += arr[i];
            best_suffix = max(best_suffix, temp_suffix);
        }

        kadanes_ans = total;
        int lastbest = 0;
        for (int i = 0; i < n; i++){
            lastbest = max(lastbest + arr[i], arr[i]);
            kadanes_ans = max(lastbest, kadanes_ans);
        }
    }
};

max_sum_val container[51];
max_sum_val merge_arrays(max_sum_val a, max_sum_val b){
    max_sum_val ans;
    ans.kadanes_ans = max({a.kadanes_ans, b.kadanes_ans, a.best_suffix + b.best_prefix});
    ans.best_prefix = max({a.best_prefix, a.total + b.best_prefix});
    ans.best_suffix = max({b.best_suffix, b.total + a.best_suffix});
    ans.total = a.total + b.total;
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--){
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            int len;
            cin >> len;
            arr[i].clear();
            for (int j = 0; j < len; j++){
                int x;
                cin >> x;
                arr[i].push_back(x);
            }
            container[i].build(arr[i]);
        }

        int merged_arr_ind[m];
        for (int i = 0; i < m; i++)cin >> merged_arr_ind[i];

        max_sum_val final_ans = container[merged_arr_ind[0]];
        for (int j = 1; j < m; j++){
            final_ans = merge_arrays(final_ans, container[merged_arr_ind[j]]);
        }
        cout << final_ans.kadanes_ans << '\n';
    }
}