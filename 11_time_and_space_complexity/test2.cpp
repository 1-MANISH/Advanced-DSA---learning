
#include<bits/stdc++.h>
using namespace std;



int main(){
	

	int t;
	cin >> t;

	while(t--){
		long long int l ,r;
		cin>> l>> r;

		long long int totalSum  , leftSum , rangeSum;

		totalSum =( r*(r+1))/2;
		leftSum = ((l-1)*(l))/2;

		rangeSum = totalSum-leftSum;

		cout<< 0LL+rangeSum<< endl;
	}

	return  0;
}