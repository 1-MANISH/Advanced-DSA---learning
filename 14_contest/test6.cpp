#include<bits/stdc++.h>
using namespace std;


int main(){

	int n ,k,t;
	cin >> n >> k >> t;
	vector<int>arr(n);
	for(int i = 0 ; i < n ; i++)
		cin >> arr[i];

	int count = 0 ;
	long long int sum = 0 ;
	for(int i = 0  ; i < k ; i ++)
		sum+=arr[i];
	long long int avg = sum/k;

	if(avg>=t)
		count++;

	for(int i = k ; i < n ; i++){
		sum =sum+arr[i]-arr[i-k];
		avg = sum/k;
		if(avg >= t)count++;
	}
	cout << count << endl;
	
	return 0;
}