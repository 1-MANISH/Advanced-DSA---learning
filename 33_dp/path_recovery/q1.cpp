#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll** dp;
string result = "";

//A. Minimum cost path sum  -  print path
//https://codeforces.com/group/4vcXCPx8NY/contest/718431/problem/A

ll solve(int row,int col,int n,int m,vector<vector<int>>&grid){

    // base case

    // cordinate in grid is not valid means not possible answer
    if(row>=n or col >= m)return INT_MAX;

    if(row==n-1 and col==m-1){ // reached the end - Wining grid
        return grid[row][col];
    }

    if(dp[row][col]!=-1) return dp[row][col];

    // we can right or down

    // let visit right wala
    ll ans1 = grid[row][col] + solve(row,col+1,n,m,grid);

    // lets try down wala
    ll ans2 = grid[row][col] + solve(row+1,col,n,m,grid);

    // we want minimum cost
    ll ans = min(ans1,ans2);

    return dp[row][col] = ans;

}

void recover(int row,int col,int n,int m,vector<vector<int>>&grid){

    // base case

    // cordinate in grid is not valid means not possible answer
    if(row>=n or col >= m)return ;

    if(row==n-1 and col==m-1){ // reached the end - Wining grid
        return ;
    }


    // we can right or down

    // let visit right wala
    ll ans1 = grid[row][col] + solve(row,col+1,n,m,grid);

    // lets try down wala
    ll ans2 = grid[row][col] + solve(row+1,col,n,m,grid);

    // we want minimum cost
    ll ans = min(ans1,ans2);

    if(ans==ans1){
        result+="R"; // we took right wala path
        recover(row,col+1,n,m,grid);
    }else{
        result+="D"; // we took down wala path
        recover(row+1,col,n,m,grid);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n  , m  ;
    cin >> n >>  m;
    vector<vector<int>>grid(n,vector<int>(m));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0  ; j < m ; j++){
            cin >> grid[i][j];
        }
    }
    
    dp = new ll*[n];
    for(int i = 0 ; i <n  ; i++){
        dp[i] = new ll[m];
        for(int j = 0 ;  j < m ; j++){
            dp[i][j]=-1;
        }
    }

    cout <<solve(0,0,n,m,grid) << endl;
    recover(0,0,n,m,grid);

    cout << result << endl;

    return 0;
}

