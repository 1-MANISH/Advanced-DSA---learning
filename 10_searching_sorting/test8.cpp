
//push zero to last
#include<bits/stdc++.h>
using namespace std;

void pushZeroToEnd(vector<int> &arr) {
    int n = arr.size();
    int zeroCount = 0;
    for(int i = 0 ;i  < n  ; i++){
    	if(arr[i]==0)zeroCount++;
    }  
    int k = 0 ;
    for(int i = 0 ; i< n ; i++){
    	if(arr[i]!=0){
    		arr[k++]=arr[i];
    	}
    }
    for(int i = 0 ; i< zeroCount ; i++){
    	arr[k++]=0;
    }
}

void printArr(vector<int>&arr){
	int n = arr.size();
	for(int i = 0 ; i < n ; i++){
		cout << arr[i] << " ";
	}cout << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>arr(n);
		for(int i = 0 ; i < n ; i++){
		 	cin >> arr[i];
		} 
		pushZeroToEnd(arr);
		printArr(arr);

	}
	 
	

	
	return  0;
}