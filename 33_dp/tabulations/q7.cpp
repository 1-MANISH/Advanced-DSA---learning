#include <bits/stdc++.h>
using namespace std;

const int BUY = 0;
const int SELL = 1;

// Buy & Sell Stock: K Transactions

/*
DIRECTION:
    REC:
        index  = 0 ---> n
        event = 0 ---> 2*k

    TAB:
        index = n to 0 
        event = 2*k to 0

*/

int solve(int index,int event,int &k,vector<int>&prices){

    // base case
    if(index==prices.size() or event==2*k){
        return 0;
    }


    // do to porform anything -  no transaction
    int ans1 = solve(index+1,event,k,prices);

    // do perform possible transaction
    int transactionType = event & 1 ? SELL : BUY;
    int ans2 = 0 ;
    if(transactionType == BUY){
        ans2 = -prices[index] +  solve(index+1,event+1,k,prices);
    }else{
        ans2 = +prices[index] + solve(index+1,event+1,k,prices);
    }

    return max(ans1,ans2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , k;
    cin >> n >> k;

    vector<int>prices(n);

    for(int i = 0  ; i < n  ; i++)
        cin >> prices[i];

    // cout << solve(0,0,k,prices);

    vector<vector<int>>dp(n+1,vector<int>(2*k+1));

    for(int index = n ; index >= 0 ; index-- ){
        for(int event = 2*k ; event >= 0 ; event-- ){

            int &ans = dp[index][event];

            // base case
            if(index==n or event==2*k){
                ans =  0;
                continue;
            }

            // do to porform anything -  no transaction
            int ans1 =dp[index+1][event];

            // do perform possible transaction
            int transactionType = event & 1 ? SELL : BUY;
            int ans2 = 0 ;
            if(transactionType == BUY){
                ans2 = -prices[index] +  dp[index+1][event+1];
            }else{
                ans2 = +prices[index] + dp[index+1][event+1];
            }

            ans =  max(ans1,ans2);

        }
    }

    cout << dp[0][0];
    return 0;
}



