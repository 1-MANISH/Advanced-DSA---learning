#include <bits/stdc++.h>
using namespace std;
#define int long long

// House robber

/*
    RECURSIVE :
        index = 0 to n
    TABULATION :
        index  =  n to 0
*/

int solve(int index,vector<int>&houses){

    // base case
    if(index>=houses.size()){
        return 0;
    }

    // not take it
    int ans1 = solve(index+1,houses);

    // take it
    int ans2 = houses[index] + solve(index+2,houses);

    return max(ans1,ans2);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int>houses(n);
    for(int i = 0  ; i < n  ; i++)
        cin >> houses[i];

    // cout << solve(0,houses);

    vector<int>dp(n+2);

    for(int index = n ; index >= 0; index--){

        int &ans = dp[index];

        // base case
        if(index>=n){
            ans =  0;
            continue;
        }

        // not take it
        int ans1 = dp[index+1];

        // take it
        int ans2 = houses[index] + dp[index+2];

        ans =  max(ans1,ans2);

    }

    cout << dp[0];
    return 0;
}



