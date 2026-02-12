#include<bits/stdc++.h>
using namespace std;

/*

Binary Search
	-
	Optimized techniques
	for searching
	into any monotonic functions
	 - where it always follows
	 a specific order

	So either function
	is monotonic yaa 
	predicate function ho to 

	Binary search lga sktee hai

	Tricks:
	FIND SEARCH SPACE
	USE END-START>1 end check last
	2 element  so that no infinite loop

	Patterns - 
	1)On sorted array search
	2)
	3)
	4)

*/


// TC = O(log(n))
// SC = O(1)
int binarySearch(vector<int>&arr,int start,int end,int &target){

	// while(start<=end){
	// 	int mid=start+(end-start)/2;
	// 	if(arr[mid]==target)return mid;
	// 	else if(arr[mid]<target)start=mid+1;
	// 	else end=mid-1;
	// }
	// return -1;

	while(end-start>1){// search space = 2 elements pr pause
		int mid=start+(end-start)/2;
		if(arr[mid]<target){
			start=mid+1;
		}
		else{
			end=mid;
		}
	}
	if(arr[start]==target)return start;
	else if(arr[end]==target)return end;
	return -1;
}

int main(){

	int n , target;
	cin >> n >> target;
	vector<int>arr(n);
	for(int i = 0  ; i < n ; i++)cin >> arr[i];

	cout << binarySearch(arr,0,n-1,target) << endl;



	return 0;
}