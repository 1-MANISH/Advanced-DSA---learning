#include <bits/stdc++.h>
using namespace std;

// https://cses.fi/problemset/task/1633
// Dice Combinations cses

const int MOD = 1e9 + 7;
const int N = 1e6;
int dp[N];

int solve(int currentSum,int &n){
    // base case
    if(currentSum==n)
        return 1;

    if(dp[currentSum]!=-1) return dp[currentSum];
    int ans = 0 ;
    for(int i = 1 ; i <= 6 ; i++){
        if(currentSum+i<=n)
            ans = (ans + solve(currentSum+i,n)) % MOD;
    }

    return dp[currentSum] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    memset(dp,-1,sizeof dp);

    cout << solve(0,n);
    
    return 0;
}
