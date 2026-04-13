/*

Find first missing postive
First Missing Positive

1<=N<=10^6
-10^9<=a[i]<=10^9


*/
#include<bits/stdc++.h>
using namespace std;

int printFirstMissingPositive(vector<int>&arr,int &n){

	for(int i = 1 ; i <= n ; i++){
		if(arr[i]>0){
			if(arr[arr[i]] != arr[i]){
				swap(arr[i],arr[arr[i]]);
				i--;
			}
		}
	}
	for(int i=1 ; i <=n ; i++){
		if(arr[i]!=i)return i;
	}
	return n+1;
}


int main(){

	int n;
	cin >> n;
	vector<int>arr(n);
	for(int i = 1 ; i<= n ; i++){
		cin >> arr[i];
	}	

	cout << printFirstMissingPositive(arr,n) << endl;

	return  0;
}