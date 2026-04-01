/*Q:
J. Smallest Subarray with Sum > K

1≤N≤10^5
1≤K≤10^18
1≤Ai≤10^9

*/
#include<bits/stdc++.h>
using namespace std;

int smallestSubArrayWithSumGreaterK(vector<int>&arr,int &n ,long long int &k){
	long long int currentSum = 0;
	int l = 0 ,ans  = INT_MAX ;
	for(int r = 0 ; r < n ; r++){
		currentSum+=arr[r];
		while(l<=r && currentSum>k){
			ans = min(ans,r-l+1);
			currentSum-=arr[l];
			l++;
		}
	}
	return ans==INT_MAX?-1:ans;
}

int main(){

	int n ;
	long long int k;
	cin >> n >> k ;
	vector<int>arr(n);
	for(int i = 0 ; i< n ; i++){
		cin >> arr[i];
	}
	cout << smallestSubArrayWithSumGreaterK(arr,n,k);

	
	return  0;
}