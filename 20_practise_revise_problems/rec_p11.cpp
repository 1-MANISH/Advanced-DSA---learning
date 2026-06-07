#include<bits/stdc++.h>
using namespace std;

void printArr(vector<int>&arr,int n){
	if(n<=0)return;
	printArr(arr,n-1);
	cout << arr[n-1] << " ";
}

int main(){

	int n;
	cin >> n;
	vector<int>arr(n);
	for(int i = 0 ; i < n ; i++)
		cin >> arr[i];
	printArr(arr,n);


	return 0;
}