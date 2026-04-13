/*
Q:
Find the smallest non-negative integer not in 

*/
#include<bits/stdc++.h>
using namespace std;



int main(){

	
	int n;
	cin >> n;
	vector<int>arr(n);
	for(int i = 0 ; i < n ; i++) cin >> arr[i];
	vector<int>correct(n+1,-1);
	for(int i = 0 ; i < n ; i++){
		correct[arr[i]]=i;
	}	
	for(int i = 0 ; i <= n ; i++){
		if(correct[i]==-1){
			cout << i  << endl;
			return 0;
		}
	}
	cout << -1 << endl;

	
	return  0;
}