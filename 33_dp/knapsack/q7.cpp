#include <bits/stdc++.h>
using namespace std;

// https://auth.learnyst.com/admin-login?domain=vit-200861

// G. Count Subsets with Given Difference
// https://codeforces.com/group/4vcXCPx8NY/contest/715177/problem/G
const int N = 1e2;
const int M = 1e4;
vector<vector<int>>dp(N+1,vector<int>(M+1,-1));

int countEqualSum(int index,int currentSum,int &totalSum,int &diff,int &n,vector<int>&arr){

    if(index>=n){
        int s2 = totalSum-currentSum;
        return currentSum-s2==diff ? 1 : 0;
    }

    if(dp[index][currentSum]!=-1){
        return  dp[index][currentSum];
    }

    // take it
    int a1 = countEqualSum(index+1,currentSum+arr[index],totalSum,diff,n,arr);


    // not take it
    int a2 = countEqualSum(index+1,currentSum,totalSum,diff,n,arr);
    
    return dp[index][currentSum]= a1 + a2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ,  diff;
    cin >> n >> diff;

    vector<int>arr(n);
    int totalSum = 0;
    for(int i = 0  ; i < n ; i++){
        cin >> arr[i];
        totalSum+=arr[i];
    }

    cout << countEqualSum(0,0,totalSum,diff,n,arr);

    return 0;

}