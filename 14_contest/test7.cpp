#include<bits/stdc++.h>
using namespace std;


int main(){

	int n ;
	cin >> n;
	vector<int>creator(n);
	for(int i = 0 ; i < n ; i++)
		cin >> creator[i];

	int ans = 1 , l = 0 , r = 0 ;
	unordered_map<int,int>mp;
	for(int r  = 0 ; r < n ; r++){
		mp[creator[r]]++;
		while(mp[creator[r]]>1 && l<=r){
			mp[creator[l]]--;
			l++;
		}	
		ans = max(ans,r-l+1);
	}

	cout << ans << endl;
	
	return 0;
}