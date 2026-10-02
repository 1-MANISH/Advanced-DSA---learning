#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
const int MOD = 1e9 + 7 ;

int dp[N];

// coin combination cses -I (order  matters)
// https://cses.fi/problemset/task/1635


int solve(int currentSum,int &x,vector<int>&coins){

    // base case
    if(currentSum==x){
        return 1;
    }

    if(dp[currentSum]!=-1)return dp[currentSum];

    int ans  = 0 ;
    for(int index = 0  ; index < coins.size() ; index++ ){

        if(currentSum+coins[index]<=x){
            ans = (ans + solve(currentSum+coins[index],x,coins))%MOD;// again we try
        }
    }

    return dp[currentSum] = ans%MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x;
    cin >> n >> x;
    vector<int>coins(n);
    for(int i  = 0 ; i < n  ; i++)
        cin >> coins[i];

    memset(dp,-1,sizeof dp);
    cout << solve(0,x,coins);
 

    return 0;
}
