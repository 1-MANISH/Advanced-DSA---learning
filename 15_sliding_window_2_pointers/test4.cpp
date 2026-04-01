
/*
Q:
LONGEST SUBARRAY HAVING SUM < X
1<=N<=10^5
1<=A[i]<=10^9 (All values are positive)
*/
#include<bits/stdc++.h>
using namespace std;


int longestSubarrayWithSumLessK(vector<int>&arr,int &n,long long int &x){
	long long int currentSum = 0 ;
	int ans = 0 , currentLen = 0,lastIndex= 0 ,currentIndex = 0 ;
	while(currentIndex<n){
		currentSum+=arr[currentIndex];
		currentLen++;
		while(lastIndex<=currentIndex && currentSum>=x){
			currentSum-=arr[lastIndex];
			lastIndex++;
			currentLen--;
		}
		ans = max(ans,currentLen);
		currentIndex++;
	}
	return max(ans,currentLen);
}

int main(){

	int n ;
	long long int x;
	cin >> n >> x ;
	vector<int>arr(n);
	for(int i = 0 ; i< n ; i++)cin >> arr[i];

	cout << longestSubarrayWithSumLessK(arr,n,x) ;
	
	return  0;
}