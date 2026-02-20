// linear search
#include<bits/stdc++.h>
using namespace std;

string linearSearch(vector<int>&arr,int &n,int &target){
	for(int i = 0 ; i < n ; i++){
		if(arr[i]==target)return "YES";
	}
	return "NO";
}


int main(){
	
	int n , target;
	cin >> n ;
	vector<int>arr(n);
	for(int i = 0 ; i < n ; i++)cin >> arr[i];
	cin >> target;
	cout << linearSearch(arr,n,target);


	
	return  0;
}