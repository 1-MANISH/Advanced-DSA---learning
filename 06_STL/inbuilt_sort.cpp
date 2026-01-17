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
		SC = O(n*log(n))

Custom Comparator:
	Defualt logic - asscending order
	Other =wise we can provide our own logic

	in comparator function
		if wants to swap - return false
		otherwise - return true


*/



void printArr(vector<int>&arr){
	for(auto &ele:arr)cout << ele << " ";
		cout << endl;
}
void printArr(vector<pair<int,int>>&arr){
	for(auto &ele:arr)cout << ele.first << " "<< ele.second << endl;
		cout << endl;
}

bool should_i_swap(int &a,int &b){
	if(a<b)return false;
	return true;

}
bool should_i_swap(pair<int,int> &a,pair<int,int> &b){
	if(a<b)return false;
	return true;

}

void basic_sort(vector<pair<int,int>>&arr,int &n){
	for(int i = 0 ; i < n ; i++){
		for(int j = i+1 ; j< n ; j++){
			if(should_i_swap(arr[i],arr[j])){
				swap(arr[i],arr[j]);
			}
		}
	}
}

// bool compartorFunction(pair<int,int>&a,pair<int,int>&b){
// 	if(a>b)return true;
// 	return false;
// }

bool compartorFunction(pair<int,int>&a,pair<int,int>&b){
	if(a.first!=b.first){
			// if(a.first>b.first)return true;
			return a.first<b.first;
			// else return false;
	}
	else{
		 	// if(a.second<b.second)return true;
			return a.second>b.second;
			// else return false;
	}
}

int main(){

		int n;
    cin >> n;
    vector<pair<int,int>>arr(n);
    for(int i = 0 ; i < n ; i++)cin >>arr[i].first >> arr[i].second;
   
    printArr(arr);
  // sort(arr.begin(),arr.end(),compartorFunction);
    sort(arr.begin(),arr.end(),compartorFunction);
 		printArr(arr);

    // printArr(arr);
	  // basic_sort(arr,n);
	  // printArr(arr);

    // sort(arr.begin(),arr.end());
      // sort(arr.begin()+2,arr.end());
    // printArr(arr);

		return 0;
}