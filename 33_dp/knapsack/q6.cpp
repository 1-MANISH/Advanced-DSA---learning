#include <bits/stdc++.h>
using namespace std;

const int M = 1e9+7;
const int N = 1e3;
const int S = 1e3;
vector<vector<int>>dp(N+1,vector<int>(S+1,-1));

// https://codeforces.com/group/4vcXCPx8NY/contest/715177/problem/F
// F. Count Subset Sum

int countSubsetSum(int index,int currentSum,int &target,int &n,vector<int>&arr){

    if(index>=n){
        return currentSum==target ? 1 : 0;
    }

    if(currentSum>target){
        return  0;// as all number are positive only
    }

    if(dp[index][currentSum]!=-1){
        return dp[index][currentSum];
    }

    // take it
    int a1 = countSubsetSum(index+1,currentSum+arr[index],target,n,arr);

    // not take it
    int a2 = countSubsetSum(index+1,currentSum,target,n,arr);


    return dp[index][currentSum] =  (a1 %M + a2 % M )%M;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,target;
    cin >> n >> target;
    vector<int>arr(n);

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    cout << countSubsetSum(0,0,target,n,arr);

    return 0;
}