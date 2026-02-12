#include<bits/stdc++.h>
using namespace std;



int main(){

	int n;
	cin >> n;
	vector<int>arr(n);
	unordered_map<int,int>mp;
	for(int i = 0 ; i < n ; i++){
		cin >> arr[i];
		mp[arr[i]]++;
	}


	for(int i = 0 ; i < n ; i++){
		if(mp[arr[i]]==1)cout << arr[i] << " ";
	}

	return 0;
}