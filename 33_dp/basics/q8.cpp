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
	ll  helper(int start , int &target,vector<int>&height){

		if(start>target){
			return 1e16;
		}

		if(start==target){
			return 0;
		}
		
		if(dp[start]!=-1){
			return dp[start]; 
		}

		ll ans1 = 0LL+abs(0LL+height[start]-height[start+1]) + helper(start+1,target,height);

		ll ans2 = 0LL+abs(0LL+height[start]-height[start+2]) + helper(start+2,target,height);

		return dp[start]= 1LL*min(ans1,ans2);

	}

	ll minCost(vector<int>&height){
		int n = height.size()-1;
		return helper(1,n,height);
	}
};

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int>height(n+1);
	for(int  i = 1 ; i <= n  ; i++){
		cin >> height[i];
	}

	Solution * sol = new Solution(n);
	cout << sol->minCost(height);

	return 0;
}