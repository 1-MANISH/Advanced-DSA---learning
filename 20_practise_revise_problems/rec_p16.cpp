#include<bits/stdc++.h>
using namespace std;
#define ll long long

int firstOccurence(vector<int>&arr,int n,ll &x){
	if(n==arr.size())return -1;
	if(arr[n]==x)
		return n+1;
	else return firstOccurence(arr,n+1,x);
	
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
	cout << firstOccurence(arr,0,x) << endl;

	return 0;
}