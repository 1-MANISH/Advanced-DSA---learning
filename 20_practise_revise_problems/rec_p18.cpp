#include<bits/stdc++.h>
using namespace std;
#define ll long long

void printOccurence(vector<int>&arr,int n,ll &x,bool &isFound){
	if(n==arr.size()){
		cout << (!isFound?"-1":"") << endl;
		return;
	}
	if(arr[n]==x){
		isFound=true;
	 	cout << n+1 << " ";
	
	}
	printOccurence(arr,n+1,x,isFound);
	
}

int main(){

	int n;
	ll x;
	bool isFound=false;
	cin >> n;
	vector<int>arr(n);
	for(int i = 0 ; i < n  ; i++){
		cin >> arr[i];
	}
	cin >> x;
	printOccurence(arr,0,x,isFound) ;

	return 0;
}