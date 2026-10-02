#include <bits/stdc++.h>
using namespace std;
#define int long long

//  minimum cost path in grid

//  recursive solutution
/*
DIRECTION :
    rec : 
        i = 0 to n
        j = 0 to m

    tab :
        i = n to 0
        j = m to 0
*/
int solve(int i,int j,int &n,int &m,vector<vector<int>>&grid){

    //base case

    if(i==n-1 and j==m-1){
        return grid[n-1][m-1];
    }

    if(i>=n or j>=m){
        return INT_MAX;
    }

    // right 
    int ans1 = grid[i][j] + solve(i,j+1,n,m,grid);

    // down
    int ans2 = grid[i][j] + solve(i+1,j,n,m,grid);

    return min(ans1,ans2);
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , m ;
    cin >> n >> m;
    vector<vector<int>>grid(n,vector<int>(m));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> grid[i][j];
        }
    }

    // cout << solve(0,0,n,m,grid);

    vector<vector<int>>dp(n+1,vector<int>(m+1));

    for(int i = n ; i >= 0 ; i--){
        for(int j = m ; j >= 0 ; j--){

            int &ans = dp[i][j];

            if(i==n-1 and j==m-1){
                ans =  grid[n-1][m-1];
                continue;
            }
            if(i>=n or j>=m){
                ans =  1e16;
                continue;
            }
            
            // right 
            int ans1 = grid[i][j] + dp[i][j+1];

            // down
            int ans2 = grid[i][j] + dp[i+1][j];

            ans =  min(ans1,ans2);
        }
    }

    cout << dp[0][0] ;
    return 0;
}

// parakeet ai

