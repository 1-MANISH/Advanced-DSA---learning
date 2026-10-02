#include <bits/stdc++.h>
using namespace std;


/*
 DIRECTIONS:
    REC :
        index = 0 ---> n
        cap = 0  ---> maxCap

    TAB :
        index = n ----> 0
        cap = maxCap ---> 0
*/

// 0/1 Knapsack

int solve(int index,int cap,int &maxCap,vector<int>&weights,vector<int>&values){

    // base cases
    if(index>=weights.size()){
        return 0;
    }

    // not take it
    int ans1 = solve(index+1,cap,maxCap,weights,values);

    // take it if possible
    int ans2 = 0 ;
    if(cap+weights[index]<=maxCap){
        ans2 = values[index] + solve(index+1,cap+weights[index],maxCap,weights,values);
    }

    return max(ans1,ans2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,maxCap;
    cin >> n >> maxCap;

    vector<int>weights(n),values(n);

    for(int i = 0  ; i< n  ; i++ )
        cin >> weights[i];
    for(int i = 0  ; i < n ; i++ )
        cin >> values[i];

    // cout << solve(0,0,maxCap,weights,values);


    vector<vector<int>>dp(n+1,vector<int>(maxCap+1,0));

    for(int index = n ; index >= 0 ;index --){
        for(int cap = maxCap ; cap >=0 ; cap--){

            int &ans = dp[index][cap];

            if(index>=n){
                ans = 0;
                continue;
            }


            // not take it
            int ans1 = dp[index+1][cap];

            // take it if possible
            int ans2 = 0 ;
            if(cap+weights[index]<=maxCap){
                ans2 = values[index] +dp[index+1][cap+weights[index]];
            }

            ans =  max(ans1,ans2);
        }
    }


    cout <<  dp[0][0];
    return 0;
}

// parakeet ai

