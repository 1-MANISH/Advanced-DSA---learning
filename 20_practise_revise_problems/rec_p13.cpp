#include<bits/stdc++.h>
using namespace std;

int arrMaximum(vector<int>&arr,int n){
	if(n<=0)return INT_MIN;
	return max(arr[n-1],arrMaximum(arr,n-1));
}

int main(){

	int n;
	cin >> n;
	vector<int>arr(n);
	for(int i = 0 ; i < n ; i++)
		cin >> arr[i];
	cout << arrMaximum(arr,n);


	return 0;
}