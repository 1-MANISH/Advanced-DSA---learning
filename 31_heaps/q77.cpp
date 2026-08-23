#include <bits/stdc++.h>
using namespace std;

bool isMinHeap(vector<int>&arr,int &n){
	int index = n-1;
	while(index>=0){
		int parent = (index-1)/2;
		if(arr[index]<arr[parent])return false;
		index--;
	}
	return true;
}

int main(){

	int n;
	cin >> n;
	vector<int>arr(n);
	for(int i = 0 ; i < n ; i++)cin >> arr[i];

	cout << (isMinHeap(arr,n)?"YES":"NO") << endl;
	return 0;
}