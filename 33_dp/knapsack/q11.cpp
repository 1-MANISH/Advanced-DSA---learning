#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/group/4vcXCPx8NY/contest/715177/problem/K

// K. Coin Combinations

/*
1<=n<=100
1<=x<=1e5

unlimited can coin be choosen

ans/1e9+7
*/

const int M = 1e9+7;
int **dp;


int coinCombinationCount(int index,int currentCoinSum,int &x,int &n,vector<int>&coin){


    if(currentCoinSum>x)return 0;

    if(currentCoinSum==x)return 1;

    if(dp[index][currentCoinSum]!=-1){
        return dp[index][currentCoinSum];
    }

    int ans = 0 ;

    for(int i = index ; i < n ; i++){
        if(currentCoinSum+coin[i]<=x){
            ans= (ans%M + coinCombinationCount(i,currentCoinSum+coin[i],x,n,coin)%M ) % M;
        }
    }

    return dp[index][currentCoinSum] =  ans%M;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x;
    cin >> n >> x;

    vector<int>coin(n);

    for(int i = 0  ; i < n ; i++)
        cin >> coin[i];

    dp = new int*[n+1];
    for(int i  = 0 ; i<=n ; i++){
        dp[i] = new int[x+1];
    }
    for(int i  = 0 ; i<=n ; i++){
        for(int j = 0 ; j<=x ; j++){
            dp[i][j] = -1;
        }
    }

    cout << coinCombinationCount(0,0,x,n,coin);


    return 0;
}
