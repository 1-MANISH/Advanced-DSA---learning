//  array rotation
#include<bits/stdc++.h>
using namespace std;

void rotateArr(vector<int>&arr,int &d){
	int n = arr.size();
	for(int i = d ; i < n ; i++){
		cout << arr[i] << " ";
	}
	for(int i = 0 ; i <= d-1 ; i++){
		cout << arr[i] << " ";
	}cout << endl;

}


int main(){
	int t;
	cin >> t;
	while(t--){
		int n,d; 
		cin >> n;
		vector<int>arr(n);
		for(int i = 0 ; i< n ; i++)cin >> arr[i];
		cin >> d;
		rotateArr(arr,d);

	}
	
	return  0;
}