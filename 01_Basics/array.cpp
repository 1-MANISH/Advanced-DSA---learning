#include<bits/stdc++.h>
using namespace std;

// const int p = 1e7;
int b[p];

int main(){

	int n;
	cin >> n;
        // comment
	int arr[n];
	for(int i = 0 ; i< n ; i++)cin >> arr[i];

	int size = sizeof(arr)/sizeof(arr[0]);
	cout << size << endl;
	for(int i = 0 ; i< size ;i++){
		cout << arr[i] << " ";
	}cout << endl << endl;

	int rows,cols;
	cin >> rows >> cols;
	int metrix[rows][cols];

	for(int i = 0 ; i < rows; i++){
		for(int j = 0 ; j < cols ; j++)cin >> metrix[i][j];
	}	
	
	int r = sizeof(metrix)/sizeof(metrix[0]);
	int c = sizeof(metrix[0])/sizeof(metrix[0][0]);

	cout << r << " "<< c << endl;
	
	for(int i = 0 ; i < rows; i++){
		for(int j = 0 ; j < cols ; j++)cout << metrix[i][j] << " ";
			cout << endl;
	}	


	int m = 1e5; 
	int a[m];
	a[m-1]=100;
	cout << a[m-1] << endl;

	b[p-1]=1000;
	cout << b[p-1] << endl;

	return 0;
}
