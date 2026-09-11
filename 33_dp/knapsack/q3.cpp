#include <bits/stdc++.h>
using namespace std;

int** dp;

// knapsack 0/1
// https://codeforces.com/group/4vcXCPx8NY/contest/715177/problem/C

int maxProfit(int index,int currentFill,int &capacity,int &n ,vector<int>&wt,vector<int>&cost){

    if(index>=n)
        return 0;

    if(dp[index][currentFill]!=-1){
        return dp[index][currentFill];
    }

    // take it
    // if possible
    int ans1 = 0 ;
    if(currentFill+wt[index]<=capacity){
        ans1 = cost[index]+maxProfit(index+1,currentFill+wt[index],capacity,n,wt,cost);
    }

    // not take it
    int ans2 = maxProfit(index+1,currentFill,capacity,n,wt,cost);

    return dp[index][currentFill]= max(ans1,ans2);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,capacity;
    cin >> n >> capacity;

    vector<int>weight(n),cost(n);

    for(int  i = 0  ; i< n ; i++)
        cin >> weight[i];

    for(int i  =0  ; i < n  ;i++)
        cin >>  cost[i];

    dp = new int*[n+1];
    for(int i = 0 ; i <= n ; i++){
       dp[i]  = new int[capacity+1];
    }
    for(int i = 0 ; i <= n ; i++){
       for(int j = 0 ; j<=capacity;j++)
         dp[i][j]=-1;
    }

        
    cout << maxProfit(0,0,capacity,n,weight,cost);

    return 0;
    
}
