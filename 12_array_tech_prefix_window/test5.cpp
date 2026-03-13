

/*
Print subarrays


*/
#include<bits/stdc++.h>
using namespace std;


void printSubarry(vector<int>&arr){
	int n = arr.size();
	for(int i = 0 ; i < n; i++){
		for(int j = i ; j < n ; j++){
			for(int k = i ; k <= j ; k++)cout << arr[k] << " ";
			cout << endl;
		}
	}
}

void printSubarraySum(vector<int>&arr){
	int n = arr.size();
	// int subArraySum = 0;
	for(int i = 0 ; i < n; i++){
		int sum = 0;
		for(int j = i ; j < n ; j++){
			sum+=arr[j];
			cout << sum << endl;
			// subArraySum+=sum;
		}
		
	}
	// cout << subArraySum<< endl;
}


void printAllSubArraySum(vector<int>&arr){
	int  n = arr.size();
	int subArraySum = 0;
	for(int i = 0 ; i < n ; i++){
		// ele * #subarray appearance count
		// ele * (start options * end options)
		 // ele * (i+1  * n -i ) 
		subArraySum+= arr[i]* ((i + 1) * (n-i));
	}
	cout << subArraySum<<endl;
}

int main(){

	int n;
	cin >> n;
	vector<int>arr(n);
	for(int i = 0 ; i < n ; i++)cin >> arr[i];


	// printSubarry(arr);
	printSubarraySum(arr);
	printAllSubArraySum(arr);
	
	return  0;
}