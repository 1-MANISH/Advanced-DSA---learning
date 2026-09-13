#include <bits/stdc++.h>
using namespace std;


// H. Minimum Sum Partition
// https://codeforces.com/group/4vcXCPx8NY/contest/715177/problem/H
/*

1<=N<=200
1<=a[i]<=100

minSum = 200*1 => 2*10^2
maxSum = 200*100 => 2*10^4


*/
const int N = 2*1e2;
const int S = 2*1e4;

vector<vector<int>>dp(N+1,vector<int>(S+1,-1));

int minSubsetSum(int index,int currentSum,int &totalSum,int &n,vector<int>&arr){

    if(index>=n){
        int s2 = totalSum-currentSum;
        return abs(currentSum-s2);
    }

    if(dp[index][currentSum]!=-1){
        return dp[index][currentSum];
    }

    int a1 = minSubsetSum(index+1,currentSum+arr[index],totalSum,n,arr);

    int a2 = minSubsetSum(index+1,currentSum,totalSum,n,arr);

    return dp[index][currentSum] =  min(a1,a2);
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ;
    cin >> n ;

    vector<int>arr(n);
    int totalSum = 0 ;
    for(int i = 0  ; i < n ; i++){
        cin >> arr[i];
        totalSum+=arr[i];
    }

    cout << minSubsetSum(0,0,totalSum,n,arr);

    return 0;

}