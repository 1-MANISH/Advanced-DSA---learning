#include <bits/stdc++.h>
using namespace std;

void heapify_down(vector<int>&arr,int i,int &n){
	int parent = i;
	while(parent<n){
		int lc = 2*parent + 1;
		int rc = 2*parent + 2;
		if(lc>=n)break;
		int bc=lc;
		if(rc<n && arr[rc]>arr[bc])bc=rc;
		if(arr[parent]>=arr[bc])break;
		swap(arr[parent],arr[bc]);
		parent=bc;
	}
}

void heapSort(vector<int>&arr,int &n){

	for(int i = n-1 ; i >=0  ;i--){
		heapify_down(arr,i,n);
	}

	for(int i = n-1 ; i>0 ;i--){
		swap(arr[0],arr[i]);
		heapify_down(arr,0,i);
	}
}


int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int>arr(n);
	for(int i = 0 ; i < n ; i++)cin >> arr[i];
	heapSort(arr,n);	
	for(int i = 0 ; i < n ; i++)cout << arr[i] << " ";
	return 0;
}