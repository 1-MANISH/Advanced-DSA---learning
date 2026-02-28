//digonal sum
#include<bits/stdc++.h>
using namespace std;

int digonalSum(vector<vector<int>>&arr){
	
	int n = arr.size();
	int i =0 , j =0 , ds = 0;
	while(i<n && j < n){
		ds+=arr[i++][j++];
	}
	// i = 0 , j = n-1;
	// while(i< n && j>=0){
	// 	if(i!=j){
	// 		ds+=arr[i][j];
	// 	}i++,j--;
	// }
	return ds;
}

int main(){

	int n ;
	cin >> n;
	vector<vector<int>>arr(n,vector<int>(n,0));
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> arr[i][j];
		}
	}
	cout << digonalSum(arr) << endl;
	
	return  0;
}