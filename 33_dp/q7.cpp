#include <bits/stdc++.h>
using namespace std;
#define ll long long
// https://codeforces.com/group/4vcXCPx8NY/contest/714790/problem/F


class Solution{
private:
	ll** dp ;
public:
	Solution(int n){
		dp = new ll*[n+1];
		for(int i = 0  ; i <= n ; i++){
			dp[i] = new ll[i+1];
		}
	}

	ll helper(int i ,int j , int n,vector<vector<int>>&arr){

		if(i==n-1){
			return arr[i][j];// reached last row
		}
		if(dp[i][j]!=-1){
			return dp[i][j];
		}
		ll ans1 = arr[i][j]+helper(i+1,j,n,arr);
		ll ans2 = arr[i][j]+helper(i+1,j+1,n,arr);

		return dp[i][j]=min(ans1,ans2);
	}

	ll minPathSum(vector<vector<int>>&arr){
		int n = arr.size();
		for(int i = 0  ; i <= n ; i++){
			for(int j = 0 ;  j <= i;j++){
				dp[i][j]=-1;
			}
		}

		return helper(0,0,n,arr);
	}
};

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>>arr;
    for(int i = 0 ; i < n ; i++){
    	vector<int>temp(i+1);
    	for(int j = 0 ; j <i+1 ; j++){
    		cin >> temp[j];
    	}
    	arr.push_back(temp);
    }
    Solution *sol = new Solution(n);
    cout << sol->minPathSum(arr);

	return 0;
}