#include <bits/stdc++.h>
using namespace std;
#define ll long long 

// J. Buy and Sell Stock with Cooldown (Print Transactions)
// https://codeforces.com/group/4vcXCPx8NY/contest/718431/problem/J

const int BUY = 0;
const int SELL = 1;
const int N = 1e5;
ll dp[N][2];



vector<int>buy;
vector<int>sell;

ll solve(int index,int transactionType,vector<int>&prices){

    //base case
    if(index>=prices.size()){
        return 0;
    }

    if(dp[index][transactionType]!=-1)return dp[index][transactionType];

    // skip this day -  not biding
    ll ans1 = solve(index+1,transactionType,prices);

    // do perform all possible transaction
    ll ans2 = 0;
    if(transactionType == BUY){ // BUY on this days
        ans2 = 0LL -prices[index] + solve(index+1,SELL,prices);
    }else{
        // complete by selling stock
        ans2  = 0LL +prices[index] + solve(index+2,BUY,prices);
        //+2 becuase 1 days as cooldown period
    }

    ll ans = max(ans1,ans2);

    return dp[index][transactionType] = ans;
}

void recover(int index,int transactionType,vector<int>&prices){

    //base case
    if(index>=prices.size()){
        return ;
    }


    // skip this day -  not biding
    ll ans1 = solve(index+1,transactionType,prices);

    // do perform all possible transaction
    ll ans2 = INT_MIN;
    if(transactionType == BUY){ // BUY on this days
        ans2 = 0LL - prices[index] + solve(index+1,SELL,prices);
    }else{
        // complete by selling stock
        ans2  = 0LL + prices[index] + solve(index+2,BUY,prices);
        //+2 becuase 1 days as cooldown period
    }

    ll ans = max(ans1,ans2);

    if(ans==ans1){
        recover(index+1,transactionType,prices);
    }else{
        if(transactionType == BUY){
            buy.push_back(index);
            recover(index+1,SELL,prices);
        }else{
            sell.push_back(index);
            recover(index+2,BUY,prices);
        }
        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int>prices(n);
    for(int i = 0  ; i < n ; i++ )
        cin >> prices[i];

    memset(dp,-1,sizeof dp);

    cout << solve(0,BUY,prices) << endl;

    recover(0,BUY,prices);
    cout << buy.size() << endl;
    for(int i = 0 ;  i < buy.size();i++){
        cout << buy[i] << " " << sell[i] << '\n';
    }

    return 0;
}

