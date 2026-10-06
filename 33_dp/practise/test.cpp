#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,m;


ll solve(int i,int j,vector<vector<int>>&grid){

    // base cases we see later

    if(i<0 or j>=m){
        return LLONG_MIN/4;
    }

    if(i==0 and j==m-1){
        return grid[i][j]==-1 ? 0 : grid[i][j];
    }
     

    // rest path result from going up
    ll restUp = solve(i-1,j,grid);

    // rest path result from going right
    ll restRight = solve(i,j+1,grid);

    ll best = max(restUp,restRight);

    ll ans = grid[i][j]==-1 ? 0 : grid[i][j];

    return best==0 ? 0 :ans + best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    cin >> n >> m;
    vector<vector<int>>grid(n,vector<int>(m));

    for(int i = 0  ; i< n  ;i++){
        for(int j = 0 ;  j < m ; j++){
            cin >> grid[i][j];
        }
    }
    
     ll ans =  solve(n-1,0,grid); // bottom-left   -> top-right
    if(ans<=0)cout << -1;
    else cout << ans;
    
    return 0;
}
