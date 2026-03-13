

/*
N. Maximum Subarray Sum of Size K


*/
#include<bits/stdc++.h>
using namespace std;

long long int maxSumWithK(vector<int>&arr,int &k){
	long long int ans = 0 , n = arr.size();
	if(k>n)return -1;
	long long int subArrSum = 0;
	for(int i = 0 ; i <k ; i++){
		subArrSum+=arr[i];
	}	
	ans = subArrSum;

	for(int i = k ; i < n ; i++){
		int exclude = arr[i-k];
		subArrSum=subArrSum+arr[i]-exclude;
		ans = max(subArrSum,ans);	
	}
	return ans;
}

int main(){

	int n , k;
	cin >> n >> k;
	vector<int>arr(n,0);
	for(int i = 0 ; i < n ; i++) cin >> arr[i];
	cout << 1LL*maxSumWithK(arr,k) << endl;		
	return  0;
}