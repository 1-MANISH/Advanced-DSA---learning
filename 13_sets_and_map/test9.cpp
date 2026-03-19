// 2 sum I
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
			cout << "TRUE\n";
			return 0;
		}
	}
	cout << "FALSE\n";



	
	return  0;
}