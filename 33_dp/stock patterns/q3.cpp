#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/group/4vcXCPx8NY/contest/716805/problem/C
//C. Buy & Sell Stock: K Transactions


const int BUY = 0 ;
const int SELL = 1;
const int N =1e3;
const int K = 1e2;
vector<vector<int>>dp(N,vector<int>(2*K,-1));

// k transactions
int solve(vector<int>&prices,int &k,int index,int event){

    if(index>=prices.size() or event == 2*k){
        return 0;
    }

    if(dp[index][event]!=-1)
        return dp[index][event];

    // skip this days - so no need to add buy price
    int ans1 = solve(prices,k,index+1,event);


    // lets perform possible transaction on this day
    int ans2 = 0 ;

    int transactionType =  event & 1 ? SELL : BUY;

    if(transactionType == BUY ){
        ans2 = -prices[index]+solve(prices,k,index+1,event+1);// let try now to sell the stock at best price
    }else{
        // lets sell this stock on best price
        ans2 = +prices[index]+solve(prices,k,index+1,event+1);
    }

    return dp[index][event] = max(ans1,ans2);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , k;
    cin >> n >> k;
    vector<int>prices(n);
    for(int i = 0 ; i <  n ; i++)
        cin >> prices[i];

    cout << solve(prices,k,0,0);

    return 0;
}

