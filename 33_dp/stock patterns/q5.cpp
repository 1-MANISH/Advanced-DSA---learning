#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/group/4vcXCPx8NY/contest/716805/problem/E
// E. Buy & Sell Stock: Unlimited Transactions + Fee

const int BUY = 0 ;
const int SELL = 1;
const int N = 1e5;

vector<vector<int>>dp(N,vector<int>(2,-1));

int solve(vector<int>&prices,int &fee,int index,int transactionType){

    if(index>=prices.size())
        return 0;

    if(dp[index][transactionType]!=-1)
        return dp[index][transactionType];

    // skip this days
    int ans1 = solve(prices,fee,index+1,transactionType);

    // do possibl tran on this day
    int ans2 = 0 ;
    if(transactionType == BUY){
        ans2 = -prices[index]+solve(prices,fee,index+1,SELL);
    }else{
        //on each transaxtion we paying trnx fee to platform
        ans2 = +prices[index]-fee+solve(prices,fee,index+1,BUY);
    }
    return dp[index][transactionType] = max(ans1,ans2);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , fee;
    cin >> n >> fee;
    vector<int>prices(n);
    for(int  i = 0  ; i < n  ; i ++)
        cin >> prices[i];

    cout << solve(prices,fee,0,BUY);



    return 0;
}

