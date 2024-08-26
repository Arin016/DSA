#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

const int boardSize = 4;
const int cellSize = 2;

bool isboardwrong = false;

int board[boardSize][boardSize];

bool check(int i, int j, int k){
    //check in row
    for(int col=0;col<boardSize;col++){
        if(col!=j and board[i][col]==k){
            return 0;
        }
    }
    //check in col
    for(int row=0;row<boardSize;row++){
        if(row!=i and board[row][j]==k){
            return 0; 
        }
    }
    //check in square
    int strow = (i/cellSize)*cellSize; //this is how you get the leader of the cell!
    int stcol = (j/cellSize)*cellSize;
    for(int row=strow;row<strow+cellSize;row++){
        for(int col=stcol;col<stcol+cellSize;col++){
            if(row!=i and col!=j and board[row][col]==k){
                return 0;
            }
        }
    }
    return 1;
}

int maskcol[boardSize], maskrow[boardSize], maskgrid[cellSize][cellSize];
//maskcol[i] tells us that in ith column what are the numbers that are already taken?
//maskrow[i] tells us that in ith row what are the numbers that are already taken?
//maskgrid[i][j] tells us that in (i, j)th leader cell what are the numbers that are already taken?

int getchoices(int i, int j){
    int taken = maskcol[j] | maskrow[i] | maskgrid[i/cellSize][j/cellSize];
    //to get n 1's --> (1<<n)-1 dp ke base cases mein likha karta tha!
    int nottaken = ((1<<(boardSize+1))-1)^taken;
    if(nottaken&1)nottaken^=1; //if 0 as a number was set were going to unset it
    return nottaken;
}

int ans = 0;
void rec(int i, int j){
    //base case
    if(j==boardSize){
        rec(i+1, 0);
        return;
    }
    if(i==boardSize){
        ans++;
        cout<<"ANS : "<<endl;
        for(int i=0;i<boardSize;i++){
            for(int j=0;j<boardSize;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    //recursive case
    if(board[i][j]==0){
        int choices = getchoices(i, j);

        //furthur optimisation
        //x&(x-1) takes off the last one
        while(choices){
            int last1 = choices^(choices&(choices-1));
            int last1pos = log2(last1);
            int k = last1pos;
            board[i][j] = k;
            maskcol[j]^=(1<<k);
            maskrow[i]^=(1<<k);
            maskgrid[i/cellSize][j/cellSize]^=(1<<k);
            rec(i, j+1);
            maskcol[j]^=(1<<k);
            maskrow[i]^=(1<<k);
            maskgrid[i/cellSize][j/cellSize]^=(1<<k);
            board[i][j] = 0;
            //remove last 1 
            choices&=(choices-1);
        }


        // for(int k=1;k<=boardSize;k++){
        //     if((choices>>k)&1){
        //         board[i][j] = k;
        //         maskcol[j]^=(1<<k);
        //         maskrow[i]^=(1<<k);
        //         maskgrid[i/cellSize][j/cellSize]^=(1<<k);
        //         rec(i, j+1);
        //         maskcol[j]^=(1<<k);
        //         maskrow[i]^=(1<<k);
        //         maskgrid[i/cellSize][j/cellSize]^=(1<<k);
        //         board[i][j] = 0;
        //     }
        // }


        // for(int k=1;k<=boardSize;k++){
        //     if(check(i, j, k)){
        //         board[i][j] = k;
        //         rec(i, j+1);
        //         board[i][j] = 0;
        //     }
        // }
    }
    else{
        //check if the given value at that pos is a valid one
        // if(check(i, j, board[i][j])){
        //     rec(i, j+1);
        // }
        // else isboardwrong = true;
        rec(i, j+1);
    }
}

void solve(){
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            int x;
            cin>>x;
            board[i][j] = x;
            maskcol[j]^=(1<<x);
            maskrow[i]^=(1<<x);
            maskgrid[i/cellSize][j/cellSize]^=(1<<x);
        }
    }
    rec(0, 0);
    cout<<ans<<endl;
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
