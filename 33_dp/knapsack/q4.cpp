#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/group/4vcXCPx8NY/contest/715177/problem/D
const int N = 200+10;
const int M = 1e4+10;
vector<vector<int>>dp(N,vector<int>(M,-1));
// {-1: not yet calulated ,  1: true, 0 : false}

bool isSubsetSum(int index,int currentSum ,int &target , int &n,vector<int>&arr){

	if(index>=n){
		return currentSum==target;
	}

	if(dp[index][currentSum] != -1){
		return dp[index][currentSum];
	}

	if(currentSum>target){
		return dp[index][currentSum] =  false;
	}

	// take it
	bool ans1 = isSubsetSum(index+1,currentSum+arr[index],target,n,arr);

	// not take it
	bool ans2 = isSubsetSum(index+1,currentSum,target,n,arr);

	return dp[index][currentSum]= ans1 or ans2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,target;
    cin >> n >> target;
    vector<int>arr(n);
    for(int i = 0 ; i < n  ; i++)
    	cin >> arr[i];

    cout << (isSubsetSum(0,0,target,n,arr) ? "YES\n":"NO\n");

    return 0;

}

// 364750c2-bb25-4c7b-aea6-30577a9712f6