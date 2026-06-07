#include<bits/stdc++.h>
using namespace std;

long long  arrSum(vector<int>&arr,int n){
	if(n<=0)return 0;
	return 0LL+arr[n-1]+arrSum(arr,n-1);
}

int main(){

	int n;
	cin >> n;
	vector<int>arr(n);
	for(int i = 0 ; i < n ; i++)
		cin >> arr[i];
	cout << arrSum(arr,n);


	return 0;
}