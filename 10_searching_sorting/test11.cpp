// check array rotation
#include<bits/stdc++.h>
using namespace std;

int findKRotate(vector<int>&arr){
	int n = arr.size();
	for(int i = 0 ; i< n-1 ; i++){
		if(arr[i]>arr[i+1])return i+1;
	}
	return -1;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n; 
		cin >> n;
		vector<int>arr(n);
		for(int i = 0 ; i< n ; i++)cin >> arr[i];
		cout << findKRotate(arr)<< endl;
	}
	
	return  0;
}