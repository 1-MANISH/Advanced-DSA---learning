#include<bits/stdc++.h>
using namespace std;


void bruteForce(vector<int>&arr,int &n){
	for(int i = 0 ; i< n ; i++){
		for(int j = i ; j < n ; j++){
			int sum = 0;
			for(int k = i ; k<=j ; k++){
				sum+=arr[k];
			}
			cout << sum << endl;
		}
	}
}

void slightlyOptimised2(vector<int>&arr,int &n){
	for(int i = 0 ; i< n ; i++){
		int sum = 0;
		for(int j = i ; j < n ; j++){
			sum+=arr[j];
			cout << sum << endl;
		}
	}
}

void slightlyOptimised1(vector<int>&arr,int &n,vector<int>&prefixSum){
	for(int i = 0 ; i< n ; i++){
		for(int j = i ; j < n ; j++){
			int sum = 0;
			if(i==0)sum=prefixSum[j];
			else sum=prefixSum[j]-prefixSum[i-1];
			cout << sum << endl;
		}
	}
}

int main(){

	int n;
	cin >> n ;
	vector<int>arr(n);
	vector<int>prefixSum(n,0);
	for(int i = 0 ; i< n ; i++){
		cin >> arr[i];
		if(i==0)prefixSum[i] = arr[i];
		else prefixSum[i]=prefixSum[i-1]+arr[i];
	}

	slightlyOptimised2(arr,n);

	
	return  0;
}