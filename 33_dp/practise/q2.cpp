#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N  = 1e2;
const int S = 1e6;
int dp[N][S];

// coni combination cses -II (order not matters,- unique solution)
// https://cses.fi/ckvo8q5wh/task/1636

/*
DIRECTIONS:
	REC:
		index = 0 to n
		curretnSum  = 0 to x
	TAB:
		index =  n to 0
		currentSum = x to 0
*/

int solve(int index,int currentSum,int &x,vector<int>&coins){

	// base case
	if(index==coins.size() or currentSum==x){
		return currentSum==x ? 1: 0;
	}

	if(dp[index][currentSum]!=-1)return dp[index][currentSum];

	// not take it
	int ans1 = solve(index+1,currentSum,x,coins);

	// take it
	int ans2 = 0;
	if(currentSum+coins[index]<=x) // also as again we take it
		ans2 = solve(index,currentSum+coins[index],x,coins);

	return dp[index][currentSum] = (ans1+ans2)%MOD; 
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n ,x;
    cin >> n >> x;
    vector<int>coins(n);
    for(int i  = 0 ; i< n  ;i++)
    	cin >> coins[i];

   	vector<vector<int>>dp(n+1,vector<int>(x+1));

   	for(int index = n ; index >= 0 ; index--){
   		for(int currentSum = x ;currentSum>= 0;currentSum--){
   			int &ans = dp[index][currentSum];
   			if(index==n or currentSum==x){
				ans = currentSum==x ? 1: 0;
				continue;
			}

			// not take it
			int ans1 = dp[index+1][currentSum];

			// take it
			int ans2 = 0;
			if(currentSum+coins[index]<=x) // also as again we take it
				ans2 =dp[index][currentSum+coins[index]];

			ans = (ans1+ans2)%MOD; 
   		}
   	}

   	cout << dp[0][0] << endl;

    return 0;
}
