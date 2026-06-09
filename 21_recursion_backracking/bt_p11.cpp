
#include<bits/stdc++.h>
using namespace std;

void permutationsAll(vector<int>&arr,int i,vector<vector<int>>&ans){

	if(i==arr.size()){
		ans.push_back(arr);
		return;
	}

	for(int j = i ; j < arr.size() ; j++){
		swap(arr[i],arr[j]);
		permutationsAll(arr,i+1,ans);
		swap(arr[i],arr[j]);
	}
}


int main(){

	int n;
	cin >> n;
	vector<vector<int>>ans;
	vector<int>arr(n);
	for(int i = 0 ; i < n ; i++)cin >> arr[i];
	permutationsAll(arr,0,ans);
	cout << ans.size() << endl;
	for(auto &per:ans){
		for(auto &ele:per)cout << ele << " ";
		cout << endl;
	}

	return 0 ;
}