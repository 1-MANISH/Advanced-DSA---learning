#include<bits/stdc++.h>
using namespace std;
#define int long long

bool isSortedArray(vector<int>&arr,int n){
	if(n==1)return true;

	return arr[n-1]>=arr[n-2] && isSortedArray(arr,n-1);
}


signed main(){

	int n;
	cin >> n;
	vector<int>arr(n);

	for(int i = 0 ; i < n ; i++)
		cin >> arr[i];

	cout << (isSortedArray(arr,n)?"YES":"NO");

	return 0;
}