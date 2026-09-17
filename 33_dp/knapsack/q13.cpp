#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/group/4vcXCPx8NY/contest/715177/problem/M
// M. Rod Cutting

int **dp;


int solve(int pices , int currentSize ,int &size , vector<int>&prices){

    if(currentSize>size)return INT_MIN;

    if(currentSize==size)return 0;

    if(dp[pices][currentSize]!=-1) return dp[pices][currentSize];

    int ans = INT_MIN;

    for(int i = pices ; i <= prices.size() ; i++){
        if(currentSize+i<=size){
            ans = max(ans,prices[i]+solve(i,currentSize+i,size,prices));
        }
    }

    return  dp[pices][currentSize] =  ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int>prices(n+1);
    for(int i = 1   ; i <= n ; i++)
        cin >> prices[i];
    int size = n;
    dp = new int*[n+1];
    for(int i = 0  ; i <= n ; i++){
        dp[i] = new int[n+1];
        for(int j = 0 ; j <= n ;j++){
            dp[i][j]=-1;
        }
    }
    cout << solve(1,0,size,prices);

    return 0;
}
