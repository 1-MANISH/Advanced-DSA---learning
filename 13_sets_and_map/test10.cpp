// 2 sum II
#include<bits/stdc++.h>
using namespace std;



int main(){

	int n ,t;
	cin >> n>> t;
	vector<int>arr(n);
	unordered_map<int,int>mp;
	for(int i = 0 ; i < n ; i++) cin >> arr[i],mp[arr[i]]=i;


	for(int i = 0  ; i< n ; i++){
		int ele = arr[i] , index = i;
		if(mp[t-ele] && mp[t-ele]!=index){
			cout << index+1 << " "<< mp[t-ele]+1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;



	
	return  0;
}