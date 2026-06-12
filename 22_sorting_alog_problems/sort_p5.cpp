
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void merge(vector<int>&arr,int &s,int &mid,int &e,ll &rPair){

	int i = s , j = mid+1 , k=s , n = mid , m = e;

	for(int i=s;i<=n;i++)cout << arr[i] << " ";
	cout << " | " ;
	for(int i=j;i<=m;i++)cout << arr[i] << " ";
		cout << endl;
	vector<int>output;//storing in decreasing order
	while(i <=n && j <= m ){
		if( i < j && (arr[i]*1LL > 2*1LL*arr[j]) ){
			rPair+=0LL+j-mid;
		}

		if(arr[i]<=arr[j])
			output.push_back(arr[i++]);
		else
			output.push_back(arr[j++]);
	}
	while(i<=n ){
		output.push_back(arr[i++]);
	}
	while(j<=m ){
		output.push_back(arr[j++]);
	}
	for(auto &ele:output){//making sorted-original array
		arr[k++]=ele;
	}

}

void mergeSort(vector<int>&arr,int s,int e,ll &rPair){
	if(s<e){
		int m = s+(e-s)/2;
		mergeSort(arr,s,m,rPair);
		mergeSort(arr,m+1,e,rPair);
		merge(arr,s,m,e,rPair);
	}
}

int main(){

	int n ;
	cin >> n;
	vector<int>arr(n);
	for(int i = 0 ; i < n ; i++)cin >> arr[i];
	ll rPair = 0 ;
	mergeSort(arr,0,n-1,rPair);
	cout << rPair << endl;
	return 0;
}