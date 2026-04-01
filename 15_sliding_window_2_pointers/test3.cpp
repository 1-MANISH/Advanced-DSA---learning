/*
Q:
Count distinct elements in every window of size  = K

*/

#include<bits/stdc++.h>
using namespace std;


void printDistinctInWindowK(vector<int>&arr,int &n,int k){
	unordered_map<int,int>mp;
	for(int i = 0 ; i < k ; i++){
		mp[arr[i]]++;
	}
	cout <<  mp.size() << " ";
	for(int i = k ; i < n ; i++){
		if(mp[arr[i-k]]==1)
			mp.erase(mp.find(arr[i-k]));
		else mp[arr[i-k]]--;
		mp[arr[i]]++;
		cout << mp.size() << " ";
	}
}



int main(){

	int n , k;
	cin >> n >> k ;
	vector<int>arr(n);
	for(int i = 0 ; i< n ; i++){
		cin >> arr[i];
	}
	printDistinctInWindowK(arr,n,k);
	
	return  0;
}