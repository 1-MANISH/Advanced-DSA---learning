#include <bits/stdc++.h>
using namespace std;
#define ll long long



class Solution{
	vector<ll>dp;
public:
	Solution(int n){
		for(int i = 0 ; i <=n ; i++){
			dp.push_back(-1);
		}
	}
	ll  helper(int start , int &target,int &k,vector<int>&height){

		if(start>target){
			return 1e16;
		}

		if(start==target){
			return 0;
		}
		
		if(dp[start]!=-1){
			return dp[start]; 
		}

		ll answer = LLONG_MAX;
		for(int i = 1  ; i <=k ; i++){
			answer = min(answer,0LL+abs(0LL+height[start]-height[start+i]) + helper(start+i,target,k,height));
		}
		
		return dp[start]= answer;

	}

	ll minCost(vector<int>&height,int &k){
		int n = height.size()-1;
		return helper(1,n,k,height);
	}
};

int main(){

	int n , k ;
	cin >> n >> k;
	vector<int>height(n+1);
	for(int  i = 1 ; i <= n  ; i++){
		cin >> height[i];
	}

	Solution * sol = new Solution(n);
	cout << sol->minCost(height,k);

	return 0;
}