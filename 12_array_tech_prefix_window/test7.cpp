

/*
Alternating Range Sum

You are given an array A
 of N
 integers. Your task is to answer Q
 queries. Each query is described by two integers L
 and R
 (1≤L≤R≤N)
, and you need to compute the alternating sum of the subarray A[L…R]
 as follows:

A[L]−A[L+1]+A[L+2]−A[L+3]+⋯±A[R]

*/
#include<bits/stdc++.h>
using namespace std;



int main(){

	int n , q; 
	cin >> n >> q;
	vector<int>arr(n+1);
	for(int i = 1 ; i <=n ; i++){
		cin >> arr[i];
	}
	vector<long long int>oddSum(n+1);
	vector<long long int>evenSum(n+1);
	for(int i = 1 ; i<=n ; i++){
		if(i&1)
			oddSum[i] = oddSum[i-1]+arr[i];
		else
			oddSum[i] = oddSum[i-1]-arr[i];

		evenSum[i]=-oddSum[i];	
	}
	while(q--){
		int l , r ;
		cin >> l >> r;

		if(l&1){
			cout << 0LL+oddSum[r]-oddSum[l-1] << endl;	
		}else{
			cout << 0LL+evenSum[r]-evenSum[l-1] << endl;
		}
	}



	
	return  0;
}