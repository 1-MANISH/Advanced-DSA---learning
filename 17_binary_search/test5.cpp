/*
Q:
Given an array (may or may not be sorted)
and some queries 
every queried contain X , count how many elements
in the array are <= x .

A = [ 7  1   6   2   8   1   5   6   9]

Queries
x = 3    => ans = 3
x = 5    => ans = 4
x = 7    => ans = 7

*/
#include<bits/stdc++.h>
using namespace std;

int lessThanXCount(vector<int>&arr,int &n,int &x){
	int start = 0 , end=  n-1, ans = -1;
	while(start<=end){
		int mid = start+(end-start)/2;
		if(arr[mid]<=x){
			ans = mid;
			start = mid+1;
		}else{
			end = mid-1;
		}
	}
	return ans+1;
}

int main(){

	int n;
	cin >> n;
	vector<int>arr(n);
	for(int i  = 0 ; i < n ; i++)
		cin >> arr[i];
	sort(arr.begin(),arr.end());
	int q;
	cin >> q;
	while(q--){
		int x;
		cin >> x;
		cout << lessThanXCount(arr,n,x) << "\n";
	}

}