
#include<bits/stdc++.h>
using namespace std;
#define ll long long


void merge(vector<int>&arr,int &s,int &mid,int &e,ll &inversion){
    int i = s , j = mid+1 , k =s  , n = mid , m = e;
    vector<int>output;

    while(i<=n && j<=m){
    	if(i<j && arr[i]>arr[j]){
    		inversion+=0LL+n-i+1;
    	}
      	if(arr[i]<=arr[j]){
         	output.push_back(arr[i++]);
      	}else{
         	output.push_back(arr[j++]);
        }
    }

    while(i<=n ){
      	output.push_back(arr[i++]);
    }
    
   	while(j<=m){
     	output.push_back(arr[j++]);
   	}
   	for(auto &ele:output){
   		arr[k++]=ele;
   	}
}

void mergeSort(vector<int>&arr,int s,int e,ll &inversion){

	if(s<e){
		int m = s+(e-s)/2;
		mergeSort(arr,s,m,inversion);
		mergeSort(arr,m+1,e,inversion);
		merge(arr,s,m,e,inversion);
	}
}

int main(){

	int n ;
	ll inversion = 0;
	cin >> n ;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++)cin >> arr[i];
    mergeSort(arr,0,n-1,inversion);
	cout << inversion << endl;
	return 0;
}