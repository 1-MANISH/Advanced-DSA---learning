#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/group/4vcXCPx8NY/contest/722152/problem/A
// longtest increasing (a < b) sub sequence

const int N = 2000;
int dp[N][N+1];

int solve(int index,int prevIndex,vector<int>&arr){

    // base cases
    if(index==arr.size())
        return 0 ;

    if(dp[index][prevIndex]!=-1) return dp[index][prevIndex];
    // not take it
    int ans1 = solve(index+1,prevIndex,arr);

    // take it  -  if we can
    int ans2 = 0 ;
    if(prevIndex == arr.size() or (arr[prevIndex] < arr[index])){
        ans2 = 1 + solve(index+1,index,arr);
    }

    return dp[index][prevIndex] = max(ans1,ans2);
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int>arr(n);

    for(int i = 0 ; i < n  ; i++)
        cin >> arr[i];

    // memset(dp,-1,sizeof dp);

    // cout << solve(0,n,arr);

    // technique 2
    vector<int>dp(n+1);
    for(int i = 0 ; i< n ; i++){

        dp[i] = 1; // single element always make sub seq

        for(int j = i-1 ; j>= 0 ; j--){

            if(arr[j]<arr[i]){
                dp[i] = max(dp[i], 1 + dp[j]); // we can extend with prev result
            }
        }
    }

    cout << *max_element(dp.begin(),dp.end());

    return 0;
}

