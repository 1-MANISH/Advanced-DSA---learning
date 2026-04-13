/*
Q:
Q:
Given an array - Size= n
Any value can be 0<=a[i]<=n-1
All integers from 0 to n-1 , which are repeating


n = 9

A = [0 1 0 2 4 6 3 1 5]


*/
#include<bits/stdc++.h>
using namespace std;


void printRepeating(vector<int>&arr,int &n){
	for(int i = 0 ; i < n ; i++){
		while(arr[i]!=arr[arr[i]]){
			swap(arr[i],arr[arr[i]]);
		}
	}
	for(int i = 0 ; i < n ; i++){
		if(arr[i]!=i){
			cout << "MISS = " << i << endl;
			if(arr[arr[i]]!=INT_MIN){
				cout <<"REP = " << arr[i] << endl;
				arr[arr[i]]=INT_MIN;
			}
		}
	}

}

int main(){

	int n;
	cin >> n;
	vector<int>arr(n);
	for(int i = 0 ; i < n ; i++){
		cin >> arr[i];
	}
	printRepeating(arr,n);


	

	
	return  0;
}