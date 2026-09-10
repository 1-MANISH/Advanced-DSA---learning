#include <bits/stdc++.h>
using namespace std;
#define ll long long


// E. Minimum Cost Path in Grid

class Solution{
    ll** dp;
public:
    Solution(int n,int m){
        dp = new ll*[n+10];
        for(int i = 0 ; i < n+10 ; i++){
            dp[i]=new ll[m+10];
        }
    }
    long long helper(int i, int j, int &n, int &m, vector<vector<int>>& gridCost) {
        
        // not possible as - index not valid
        if (i >= n or j >= m)
            return 1e16;

        // reached at bottom right end - a[n-1][m-1];
        if (i == n - 1 and j == m - 1)
            return gridCost[n-1][m-1];

        // answer already exist
        if (dp[i][j] != -1)
            return dp[i][j];

        // right or down

        ll ans1 = 0LL + gridCost[i][j] + helper(i, j + 1, n, m, gridCost) ; // right

        ll ans2 = 0LL + gridCost[i][j] +helper(i + 1, j, n, m, gridCost) ; // down

        return dp[i][j] = min(ans1,ans2);
    }

    ll minPathSum(vector<vector<int>>& grid) {
        int n = grid.size()  , m  = grid[0].size();
        for(int i = 0 ; i < n+1 ; i++){
            for(int j = 0 ; j < m+1 ; j++){
                dp[i][j]=-1;
            }
        }
         
        return 1LL*helper(0,0,n,m,grid);
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , m;
    cin >> n >> m;
    vector<vector<int>>gridCost(n,vector<int>(m));
    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j < m ; j++){
            cin >> gridCost[i][j];
        }
    }

    Solution* sol = new Solution(n,m);
    cout << sol->minPathSum(gridCost);

    return 0;
}