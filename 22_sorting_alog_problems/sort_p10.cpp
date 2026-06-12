
#include<bits/stdc++.h>
using namespace std;

bool campare(int &a,int &b){
	return a>b;
}

int main(){

	int n ;
	cin >> n;
	vector<int>arr(n);
	for(int i = 0 ; i< n ; i++)cin >> arr[i];
	sort(arr.begin(),arr.end(),campare);
	for(int i = 0 ; i< n ; i++)cout << arr[i] << " ";	
	return 0;
}