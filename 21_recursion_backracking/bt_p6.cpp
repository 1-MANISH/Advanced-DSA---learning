
#include<bits/stdc++.h>
using namespace std;



void printAllSubsequencesWithSumK(vector<int>&arr,int &n,int &k,int i,vector<int>&output,vector<vector<int>>&ans,long long sum){

	if(i==n){
		if(sum==k){
			ans.push_back(output);
		}
		return;
	}

	// take it
	output.push_back(arr[i]);
	printAllSubsequencesWithSumK(arr,n,k,i+1,output,ans,sum+arr[i]+0LL);
	output.pop_back();
	

	// not take it
	printAllSubsequencesWithSumK(arr,n,k,i+1,output,ans,sum);

	
}


int main(){

	int n,k;
	cin >> n>>k;
	vector<int>arr(n);
	for(int i = 0 ; i < n ; i++)
		cin >> arr[i];
	vector<vector<int>>ans;
	vector<int>output;
	printAllSubsequencesWithSumK(arr,n,k,0,output,ans,0);

	cout << ans.size() << endl;
	for(auto &sub:ans){
		for(auto &ele:sub){
			cout << ele <<  " ";
		}cout << endl;
	}
	

	return 0;
}