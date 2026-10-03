#include <bits/stdc++.h>
using namespace std;

// https://cses.fi/problemset/task/3359
// minimal grid path
const int N = 1e3+1;

string dp[N][N];

string lexMin(string &a,string &b){
    if(a[a.size()-1]=='[')
        return b;
    
    if(b[b.size()-1]=='[')
        return a;

    return a < b ? a : b;
}

string solve(int i,int j,int n,vector<vector<char>>&grid){

    // base cases

    if(i==n or j==n){
        return "[";
    }

    if(i==n-1 and j==n-1){
        return grid[n-1][n-1]+"";
    }

    if(dp[i][j]!=".") return dp[i][j];
    // take right
    string ans1 = grid[i][j]+solve(i,j+1,n,grid);

    // take down
    string ans2 = grid[i][j]+solve(i+1,j,n,grid);

    return dp[i][j] = lexMin(ans1,ans2);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<char>>grid(n,vector<char>(n));

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j  < n ; j++){
            cin >> grid[i][j];
        }
    }

    for(int  i =  0 ; i < n ; i++){
        for(int j = 0 ; j <n ; j++){
            dp[i][j]=".";
        }
    }

    cout << solve(0,0,n,grid)+grid[n-1][n-1];
    
    return 0;
}
