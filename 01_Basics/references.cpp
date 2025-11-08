#include<bits/stdc++.h>
using namespace std;

// array by defualt pass by reference
void printArray(int arr[]){
	arr[9]=100;

}

void print2DArray(int arr[][4]){
	arr[0][0]=100;
}

int main(){
	int arr[10] ;
	int arr2[4][4];
	arr[9]=900;
	arr2[0][0]=900;

	cout << arr[9] << endl;
	printArray(arr);
	cout << arr[9] << endl;

	cout << arr2[0][0] << endl;
	print2DArray(arr2);
	cout << arr2[0][0] << endl;
	return 0;
}