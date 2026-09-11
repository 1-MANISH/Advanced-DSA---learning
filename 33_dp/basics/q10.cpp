#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
	vector<ll>dp;

public:

	Solution(int n){
		for(int i = 0 ; i <=n+10 ; i++){
			dp.push_back(-1);
		}
	}

	ll helper(int start,int &n,vector<int>&house){
		cout << start << endl;
		if(start>n){
			return 0;
		}
		ll ans = LLONG_MIN;
		for(int i = start ; i <=n ; i++){
			ans = max(ans,0LL+house[start]+helper(i+2,n,house));
			cout << endl << ans << endl;
		}

		return ans;
	}

	ll maxRob(vector<int>&house){
		int n = house.size()-1; // 1 based index
		ll ans = LLONG_MIN;
		for(int start = 1 ;  start<=n ; start++){
			ans = max(ans, helper(start,n,house));
		}
		return ans;
		
	}

};

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int>house(n+1);
    for(int i = 1 ; i <= n ; i++)
    	cin >> house[i];

    Solution *sol = new Solution(n);
    cout << sol->maxRob(house) << endl;

	return 0;
}