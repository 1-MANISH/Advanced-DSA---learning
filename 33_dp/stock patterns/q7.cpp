#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int NONE  = 0;
const int NORMAL_TRAN = 1;
const int SHORT_SELL = 2;
const int N = 1e3;
const int K = 1e3;
ll dp[N][K][3];

// #https://codeforces.com/group/4vcXCPx8NY/contest/716805/problem/G
// #G. Buy & Sell Stock: Short Selling + K Transactions

ll solve(int index,int event,int transactionType,int &k,vector<int>&prices){


    // base case
    if(index==prices.size() or event==2*k){// means started trnx completed
        return transactionType == NONE ? 0 : INT_MIN;
    }

    if(dp[index][event][transactionType]!=LLONG_MIN)return dp[index][event][transactionType];

    // let skip this day
    ll ans1 = solve(index+1,event,transactionType,k,prices);

    // do perform all transactions
    ll ans2 = INT_MIN , ans3 =INT_MIN;

    if(transactionType == NONE){ // now 2 options 1. normal trnx 2. short sell trnx
        // starting a new trnx
        // normal trnx -  buy then sell
        ans2 = -prices[index] + solve(index+1,event+1,NORMAL_TRAN,k,prices);

        // short sell trnx -  sell then buy
        ans3 = +prices[index] + solve(index+1,event+1,SHORT_SELL,k,prices);

    }else if(transactionType == NORMAL_TRAN){// need to complete this normal trnx
        ans2 = +prices[index] + solve(index+1,event+1,NONE,k,prices);
    }else{ // need to complete this short sell trnx
        ans3 = -prices[index] + solve(index+1,event+1,NONE,k,prices);
    }

    return dp[index][event][transactionType] = max(ans1,max(ans2,ans3));
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,  k ; 
    cin >> n  >> k;

    vector<int>prices(n);
    for(int i = 0 ; i < n ; i++)
        cin >> prices[i];

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            for(int p = 0 ; p < 3 ; p++){
                dp[i][j][p]=LLONG_MIN;
            }
        }
    }

    cout << solve(0,0,NONE,k,prices);




    return 0;
}

