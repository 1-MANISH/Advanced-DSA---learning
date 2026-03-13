/*

. Sum of All Subarrays Separately (Hard)
time limit per test1 second
memory limit per test256 megabytes
You are given an array of n
 integers a1,a2,…,an
.

For each starting index L
 (1≤L≤n)
, print all subarrays∗
 that begin at L
 in increasing order of their ending index R
. For each subarray, print its sum.

∗
A subarray is a contiguous sequence of elements within an array. For example, the subarrays of [1, 2, 3] are [1], [2], [3], [1, 2], [2, 3], and [1, 2, 3].

Input
The first line contains an integer n
 (1≤n≤3000
) — the number of elements.
The second line contains n
 integers a1,a2,…,an
 (1≤ai≤106
).
Output
For each subarray print its sum in order as described above.
*/


#include<bits/stdc++.h>
using namespace std;

void printSumOfSubArrays(vector<int>&arr,int &n){
	for(int i = 0 ; i < n ; i++){
		int sum = 0 ;
		for(int j = i ; j < n ; j++){
			sum+=arr[j];
			cout << sum << "\n";
		}
	}
}

int main(){
	
	int n;
	cin >> n ;
	vector<int>arr(n);
	for(int i = 0 ; i< n ; i++)cin >> arr[i];
    printSumOfSubArrays(arr,n);

	return 0;
}