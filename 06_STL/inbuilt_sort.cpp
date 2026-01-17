#include<bits/stdc++.h>
using namespace std;


/*

C++ STL has inbuilt sort
algorithm and its function to use


Inbuilt Sort _ one of the best
	
	int arr[n];
	sort(arr,arr+n,comparator-optional);
	sort(arr.begin(),arr.end())
	default - accessending order


IMplementation:
	c++ me
		INtro sort : Best sorting 
			mixture of 3 sorting algorithm
			Quick + Heap + insertion
		
		Start with Quick
			if recurstion depth is high than => Heap
			number of elem <<< Insertion
	
		TC = O(n*log(n))
		SC = 
*/

void printArr(vector<int>&arr){
	for(auto &ele:arr)cout << ele << " ";
		cout << endl;
}

int main(){

		int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++)cin >>arr[i];

    	
    printArr(arr);
    sort(arr.begin(),arr.end());
      // sort(arr.begin()+2,arr.end());
    printArr(arr);

		return 0;
}