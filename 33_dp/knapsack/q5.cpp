#include <bits/stdc++.h>
using namespace std;

// E. Partition Into Equal Sum
// https://codeforces.com/group/4vcXCPx8NY/contest/715177/problem/E
const int N = 1e2;
const int M = 1e5;
vector<vector<int>>dp(N+1,vector<int>(M+1,-1));

bool isEqualSum(int index,int currentSum,int &totalSum,int &n,vector<int>&arr){

    if(index>=n){
        return currentSum==totalSum-currentSum;
    }

    if(dp[index][currentSum]!=-1){
        return dp[index][currentSum];
    }

    // take it
    bool a1 = isEqualSum(index+1,currentSum+arr[index],totalSum,n,arr);


    // not take it
    bool a2 = isEqualSum(index+1,currentSum,totalSum,n,arr);

    return dp[index][currentSum]= a1 or a2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n ;

    vector<int>arr(n);
    int totalSum = 0;
    for(int i = 0  ; i < n ; i++){
        cin >> arr[i];
        totalSum+=arr[i];
    }

    cout << (isEqualSum(0,0,totalSum,n,arr)?"YES\n":"NO\n");

    return 0;

}