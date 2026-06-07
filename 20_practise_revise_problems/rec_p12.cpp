#include<bits/stdc++.h>
using namespace std;

int arrMinimum(vector<int>&arr,int n){
	if(n<=0)return INT_MAX;
	return min(arr[n-1],arrMinimum(arr,n-1));
}

int main(){

	int n;
	cin >> n;
	vector<int>arr(n);
	for(int i = 0 ; i < n ; i++)
		cin >> arr[i];
	cout << arrMinimum(arr,n);


	return 0;
}