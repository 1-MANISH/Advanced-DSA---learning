#include <bits/stdc++.h>
using namespace std;


//https://codeforces.com/group/4vcXCPx8NY/contest/716805/problem/B
// B. Buy & Sell Stock: 2 Transactions -  4 events (buy->sell,buy->sell)

const int BUY  = 0 ;
const int SELL = 1 ;
const int N = 1e5;
const int K = 2;
vector<vector<int>>dp(N,vector<int>(2*K,-1));

int solve(vector<int>&prices,int index,int event){

    if(index>=prices.size() or event>=4){
        return 0;
    }

    if(dp[index][event]!=-1)
        return dp[index][event];

   
    // skip this days - 
    int ans1 = solve(prices,index+1,event);

    // do perform all possible event on this day
    int ans2 = 0 ;
     int transactionType = event & 1 ? SELL : BUY;

    if(transactionType == BUY){
        ans2 = -prices[index]+solve(prices,index+1,event+1);
    }else{
        ans2 = +prices[index]+solve(prices,index+1,event+1);// 2 transactions
    }

    return dp[index][event] = max(ans1,ans2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int>stockPrices(n);
    for(int i = 0  ; i < n ; i++)
        cin >> stockPrices[i];

    cout << solve(stockPrices,0,0);

    return 0;
}

