#include<bits/stdc++.h>
using namespace std;
#define ll long long

int lastOccurence(vector<int>&arr,int n,ll &x){
	if(n<0)return -1;
	if(arr[n]==x)
		return n+1;
	else return lastOccurence(arr,n-1,x);
	
}

int main(){

	int n;
	ll x;
	cin >> n;
	vector<int>arr(n);
	for(int i = 0 ; i < n  ; i++){
		cin >> arr[i];
	}
	cin >> x;
	cout << lastOccurence(arr,n-1,x) << endl;

	return 0;
}