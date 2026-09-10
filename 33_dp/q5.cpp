#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
const int M = 1e6;
int dp[N+1][M+1];


// paths in grid (right and down)

int f(int i , int j , int &n , int  &m){
    
    if(i>=n or j>=m)return 0 ;

    if(i==n-1 && j == m-1)return 1;
    
    if(dp[i][j]!=-1)return dp[i][j];

    // right + down
    return dp[i][j] =  f(i,j+1,n,m)+f(i+1,j,n,m);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , m;
    cin >> n >> m;

    for(int i = 0 ; i < n+1 ; i++){
    	for(int j = 0 ; j < m+1 ; j++){
            dp[i][j]=-1;
        }
    }

    cout << f(0,0,n,m);

    return 0;
}