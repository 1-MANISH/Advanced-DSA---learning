
/*
Q:
SHORTEST SUBARRAY WITH SUM > X

1<=n<=10^6
1<=a[i]<=10^9

9 20
1 7 5 15 5 9 15 6 9
output = 2

9 20
1 7 8 15 7 9 15 6 9
output = 2



*/
#include<bits/stdc++.h>
using namespace std;

int shortestSubArrayWithSumGRETX(vector<int>&arr,int &n,int &x){
	int ans  = INT_MAX, currentSum = 0  , l = 0 ,r = 0;
	while(r<n){
		currentSum+=arr[r];
		while(l<r && currentSum-arr[l]>x){
			currentSum-=arr[l];
			l++;
		}
		if(currentSum>x)ans = min(ans,r-l+1);
		r++;
	}
	return ans;
}

int shortestSubArrayWithSumGRETX2(vector<int>&arr,int &n,int &x){
	int ans  = INT_MAX, currentSum = 0  , l = 0 ,r = 0;
	while(r<n){
		currentSum+=arr[r];
		while(l<r && currentSum>x){
			ans = min(ans,r-l+1);
			currentSum-=arr[l];
			l++;
		}
		r++;
	}
	return ans;
}

int main(){

	int n,x;
	cin >> n >> x;
	vector<int>arr(n);
	for(int i = 0  ; i < n ; i++){
		cin >> arr[i];
	}

	cout << shortestSubArrayWithSumGRETX2(arr,n,x);

	
	return  0;
}