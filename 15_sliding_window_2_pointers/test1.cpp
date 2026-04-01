/*Q:
Max Subarray sum of size = k

*/
#include<bits/stdc++.h>
using namespace std;

long long int maxSubarraySumSizeK(vector<int>&arr,int &n , int &k){
	long long int ans ;
	long long int subSum = 0;
	for(int i = 0 ; i< k ; i++)
		subSum+=arr[i];
	ans = subSum;
	for(int i = k ; i < n ; i++){
		subSum=subSum+arr[i]-arr[i-k];
		ans=max(ans,subSum);
	}
	return max(ans,subSum);
}

int main(){

	int n , k;
	cin >> n >> k ;
	vector<int>arr(n);
	for(int i = 0 ; i< n ; i++){
		cin >> arr[i];
	}
	cout << 0LL+maxSubarraySumSizeK(arr,n,k);

	
	return  0;
}