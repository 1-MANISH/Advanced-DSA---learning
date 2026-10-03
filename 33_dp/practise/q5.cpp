#include <bits/stdc++.h>
using namespace std;

// https://cses.fi/problemset/task/1638
// grid path -I cses
const int MOD = 1e9 + 7;
const int N = 1e3;
int dp[N][N];

int solve(int i,int j,int &n,vector<vector<char>>&grid){

    // base case


    if(i>=n or j>=n) return 0;

    if(i==n-1 and j==n-1)return 1;

    if(dp[i][j]!=-1) return dp[i][j];

    int ans1 = 0 ;
    if(j+1<n && grid[i][j+1]=='.')
        ans1 = solve(i,j+1,n,grid);

    int ans2 = 0;
    if(i+1<n && grid[i+1][j]=='.')
        ans2 =solve(i+1,j,n,grid);

    return  dp[i][j] = (ans1+ans2)%MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<char>>grid(n,vector<char>(n));

    for(int i = 0 ; i < n  ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> grid[i][j];
        }
    }
    if(grid[0][0]=='*'){
        cout << 0 << endl;
        return 0;
    }
    memset(dp,-1,sizeof dp);
    cout <<solve(0,0,n,grid);

 
    
    return 0;
}
