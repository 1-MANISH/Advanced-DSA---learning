
/*
D. Count Good Numbers

*/
#include<bits/stdc++.h>
using namespace std;


void goodNumbersInWindowK(vector<int>&a,int &n,unordered_map<int,int>&good,int &m ,int &k){
	vector<int>prefix(n,0);
	prefix[0]=good[a[0]];
	for(int i = 1  ; i < n ; i++){
		prefix[i] = prefix[i-1]+good[a[i]];
	}
	for(int i = k -1 ; i < n ; i++){
		if(i==k-1)cout << prefix[i] << " ";
		else cout << prefix[i]-prefix[i-k] << " ";
	}
}


int main(){

	int n ,m , k;
	cin >> n >> m >> k ;
	vector<int>arr(n);
	unordered_map<int,int>good;
	for(int i = 0 ; i < n ; i++){
		cin >> arr[i];
	}
	for(int i = 0 ; i < m ; i++){
		int ele;
		cin >> ele;
		good[ele]=1;
	}
	goodNumbersInWindowK(arr,n,good,m,k);


	
	return  0;
}