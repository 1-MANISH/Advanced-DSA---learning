#include <bits/stdc++.h>
using namespace std;

// L. Coin Change
// https://codeforces.com/group/4vcXCPx8NY/contest/715177/problem/L


/*

1 ≤ n ≤ 10^3
0 ≤ sum ≤ 10^4

1 ≤ n⋅sum ≤ 10^6
1 ≤ coins[i] ≤ 10^4


*/

int** dp;

int minCoinRequired(int index,int currentCoinSum,int &x,int &n,vector<int>&coin){
    

    if(currentCoinSum>x)return INT_MAX-1;

    if(currentCoinSum==x)return 0;

    if(dp[index][currentCoinSum]!=-1)
        return dp[index][currentCoinSum];

    int ans = INT_MAX-1;

    for(int i = index ; i < n ; i++){
        if(currentCoinSum+coin[i]<=x){
            // +1 as we took this coin
            ans = min(ans , 1+minCoinRequired(i,currentCoinSum+coin[i],x,n,coin));
        }
    }

    return dp[index][currentCoinSum] =  ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ,x;
    cin >> n >> x;

    vector<int>coin(n);

    for(int i  = 0 ; i < n ; i++)
        cin >> coin[i];

    dp = new int*[n+1];
    for(int i = 0  ; i <= n ; i++){
        dp[i]=new int[x+1];
    }
    for(int i = 0 ;  i<=n ;i++){
        for(int j = 0 ; j <=x ; j++){
            dp[i][j]=-1;
        }
    }


    int ans = minCoinRequired(0,0,x,n,coin);

    cout << (ans==INT_MAX-1 ? -1 :ans );

    return 0;
}
