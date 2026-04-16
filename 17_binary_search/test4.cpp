/*

Q:
Print how many time target occurrence in in the array
count = last Occurrence- firtOccurence+1
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
int lastOccuranceIndex(vector<int>&arr,int &n,int &target ){
	int start = 0  , end = n-1 , ans = -1;
	while(start<=end){
		int mid = start+(end-start)/2;
		if(arr[mid]==target){
			ans = mid;
			start = mid+1;
		}else if(arr[mid]<target){
			start=mid+1;
		}else{
			end=mid-1;
		}
	}
	return ans;
}

int countOccurrence(vector<int>&arr,int &n,int &target){
	int fo  = firstOccuranceIndex(arr,n,target);
	if(fo!=-1){
		int lo = lastOccuranceIndex(arr,n,target);
		return lo-fo+1;
	}else{
		return 0;
	}
}


int main(){

	int n , target;
    cin >> n >> target;
    vector<int>arr(n);
    for(int i = 0  ; i < n ; i++)
		cin >> arr[i];

   cout << countOccurrence(arr,n,target) << endl;

}