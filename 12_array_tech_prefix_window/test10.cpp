

/*
Sum of all subarrays


*/
#include<bits/stdc++.h>
using namespace std;

long long int subArraySum(vector<int>&arr,int &n){
	long long int ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		long long int sum = 0;
		for(int j = i ;  j < n ; j++){
			sum+=arr[j];
			ans+=sum;
		}
	}
	return ans;
}

int main(){

	int n;
	cin >> n;
	vector<int>arr(n,0);
	for(int i = 0 ; i < n ; i++) cin >> arr[i];


	cout << 1LL*subArraySum(arr,n) << endl;		

	
	return  0;
}