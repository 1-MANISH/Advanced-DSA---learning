#include <bits/stdc++.h>
using namespace std;


// I. Target Sum
// https://codeforces.com/group/4vcXCPx8NY/contest/715177/problem/I
/*

1≤n≤20

−1000≤target≤1000

a1,a2,…,an(0≤ai≤1000)

0≤∑ai≤1000

This should be range
minSum = 20*(-1000) => -2*10^4
maxSum = 20*(+1000) => +2*10^4

but possible sum given if all +ve then 10^3 so
minSum = -1e3
maxSum = +1e3

n = 20
S = 1e6

*/

const int N = 20+1;
const int S = 1e6+1;
const int X = 1e3+1;

vector<vector<int>>dp(N+1,vector<int>(S+1,-1));

int targetSumCount(int index,int currentSum,int &targetSum,int &n,vector<int>&arr){

    if(index>=n){
        return currentSum == targetSum;
    }

    if(dp[index][currentSum+X]!=-1){
        return dp[index][currentSum+X];
    }

    // take +
    int a1 = targetSumCount(index+1,currentSum+arr[index],targetSum,n,arr);

    // take -
    int a2 = targetSumCount(index+1,currentSum-arr[index],targetSum,n,arr);

    return dp[index][currentSum+X]=  a1+a2;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , targetSum ;
    cin >> n >> targetSum;

    vector<int>arr(n);

    for(int i = 0  ; i < n ; i++){
        cin >> arr[i];

    }

    cout << targetSumCount(0,0,targetSum,n,arr);

    return 0;

}