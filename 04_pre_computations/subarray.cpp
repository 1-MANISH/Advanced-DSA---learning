#include<bits/stdc++.h>
using namespace std;

void printSubArray(vector<int>&arr,int &n){
	for(int i = 0 ; i < n ; i++){
		for(int j = i ; j < n ; j++){
			int sum = 0 ;
			for(int k = i ; k<=j ; k++){
				sum+=arr[k];
			}
			cout << "len = (" << j-i+1 <<  ") = " << sum << endl;
		}
	}
}

// only for positive numbers
int maxSumKSubArray(vector<int>&arr,int &n,int &K){
	int maxiLen=-1;
	for(int i = 0 ; i < n ; i++){
		int sum = 0 ;
		for(int j = i ; j < n ; j++){
			sum+=arr[j];
			if(sum==K)maxiLen=max(maxiLen,j-i+1);
			if(sum>K)break;
		}
	}
	return maxiLen;
}

int maxSumArrayLen(vector<int>&arr,int &n,int &k){
	unordered_map<int,int>mp;//sum--->index;
	int sum = 0 ,ans  = -1 ,previous_sum = 0;
	for(int i  = 0 ; i< n ; i++){
		previous_sum+=arr[i];
		if(mp.find(previous_sum-k)!=mp.end()){
			int index = mp[previous_sum-k];
			ans = max(ans,i-index);
		}
		mp[previous_sum]=i;
	}
	return ans;
}

int main(){

	int N ,K;
	cin >> N >> K;
	vector<int>arr(N);
	for(int i = 0 ; i < N ;i++)cin >> arr[i];

	
	// printSubArray(arr,N);

	// cout << maxSumKSubArray(arr,N,K) << endl;
	cout << maxSumArrayLen(arr,N,K) << endl;
	return 0;
}

// TC= O(n)+O(q)= O(n)