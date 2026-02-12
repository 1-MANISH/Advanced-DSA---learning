#include<bits/stdc++.h>
using namespace std;

void helper(vector<int>&nums,int prevIndex,int currentIndex , int n ,int currentLen, int &ansLen , int andRes){

	if(currentIndex==n){
		ansLen= max(currentLen,ansLen);
		return;
	}

	if(prevIndex==currentIndex ){
		// take
		ansLen = max(ansLen,currentLen+1);
		helper(nums,currentIndex,currentIndex+1,n,currentLen+1,ansLen,andRes&nums[currentIndex]);

		// not take
		helper(nums,prevIndex,currentIndex+1,n,currentLen,ansLen,andRes);
	}else{
		if(nums[currentIndex]>nums[prevIndex] && (andRes & nums[currentIndex])){
			// take
			ansLen = max(ansLen,currentLen+1);
			helper(nums,currentIndex,currentIndex+1,n,currentLen+1,ansLen,andRes&nums[currentIndex]);

			// not take
			helper(nums,prevIndex,currentIndex+1,n,currentLen,ansLen,andRes);
		}else{
			helper(nums,prevIndex,currentIndex+1,n,currentLen,ansLen,andRes);
		}
		
	}
}


int longestSubsequence(vector<int>& nums) {
	int n = nums.size(),ansLen = 0;
	helper(nums,0,0,n,0,ansLen,nums[0]);
	return ansLen;
}

int main(){

	int n ;
	cin >> n ;
	vector<int>arr(n);
	for(int i = 0 ;  i< n ;  i++)
		cin >> arr[i];
	
	cout <<longestSubsequence(arr) << endl;



	return  0;

}