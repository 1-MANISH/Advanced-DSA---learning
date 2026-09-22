#include <bits/stdc++.h>
using namespace std;

const int BUY  = 0;
const int SELL = 1;

// #https://codeforces.com/group/4vcXCPx8NY/contest/716805/problem/G
// #G. Buy & Sell Stock: Short Selling + K Transactions


int solve(vector<int>&prices,int &k,int index,int transactionType,int event){


    // base case
    if(index >= prices.size() or event == 2*k)
        return 0;

    // do not perform any operation - skip this  day

    int ans1 = solve(prices,k,index+1,transactionType,event);

    // do all possible transaction

    int ans2 = 0 ;

    if(transactionType == BUY){
         ans2 = -prices[index] + solve(prices,k,index+1,SELL,event+1);
    }else{
         ans2 = +prices[index] + solve(prices,k,index+1,BUY,event+1);
    }

    return max(ans1,ans2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,  k ; 
    cin >> n  >> k;

    vector<int>prices(n);
    for(int i = 0 ; i < n ; i++)
        cin >> prices[i];

    cout << solve(prices,k,0,BUY,0);


    return 0;
}

