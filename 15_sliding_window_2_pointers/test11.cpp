/*Q:
H. Count Subarrays with Sum < K

1≤N≤10^5
1≤K≤10^18
1≤Ai≤109

*/
#include<bits/stdc++.h>
using namespace std;

long long int countSubArrayWithSumLessThanK(vector<int>&arr,int &n , long long int &k){
	long long int currentSum = 0 ;
	int  l = 0, r = 0;
	long long int count = 0 ;
	for(int r  = 0 ;r < n ; r++){
		currentSum+=arr[r];
		while(l<=r && currentSum>=k){
			currentSum-=arr[l];
			l++;
		}
		count+=(r-l+1);
	}
	return count;
}

int main(){

	int n ;
	long long int k;
	cin >> n >> k ;
	vector<int>arr(n);
	for(int i = 0 ; i< n ; i++){
		cin >> arr[i];
	}
	cout << countSubArrayWithSumLessThanK(arr,n,k);

	
	return  0;
}