#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;


// climb stairs

// direction
// recursion - 0 ----> N

// tabulation - N ---> 0

int solve(int index,int &n){
    // base case

    if(index==n) return 1;
    if(index > n) return 0;

    int ans1 = solve(index+1,n);

    int ans2 = solve(index+2,n);

    return (ans1+ans2) % MOD;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int>dp(n+2);

    for(int index =  n ; index >= 0 ;index--){

        int &ans = dp[index];

        if(index==n) {
            ans = 1;
            continue;
        }
        if(index > n){
            ans = 0;
            continue;
        }

        int ans1 = dp[index+1];

        int ans2 = dp[index+2];

        ans  = (ans1+ans2) % MOD;
    }

    cout << dp[0];

    return 0;
}



/*

n = 4

dp[n+2] = [5 3 2 1 1 0 ]
          [0 1 2 3 4 5 ]

    dp[2] -> number of ways to go from 2 to 5

*/

