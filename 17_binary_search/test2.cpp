/*
Q:
Find first occurrence of target in sorted array


*/

#include<bits/stdc++.h>
using namespace std;


int firstOccuranceIndex(vector<int>&arr,int &n,int &target ){
	int start = 0  , end = n-1 , ans = -1;
	while(start<=end){
		int mid = start+(end-start)/2;
		if(arr[mid]==target){
			ans = mid;
			end = mid-1;
		}else if(arr[mid]<target){
			start=mid+1;
		}else{
			end=mid-1;
		}
	}
	return ans;
}

int main(){

	int n , target;
    cin >> n >> target;
    vector<int>arr(n);
    for(int i = 0  ; i < n ; i++)
		cin >> arr[i];

   cout << firstOccuranceIndex(arr,n,target) << endl;

}