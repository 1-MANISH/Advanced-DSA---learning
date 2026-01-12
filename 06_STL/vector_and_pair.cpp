#include<bits/stdc++.h>
using namespace std;

// pairs - class in c++

/*		
		To maintain relationship b/w things
		pair<dt1,dt2>pr;
		dt1 and dt2 can be data type or
		container

		pr = make_pair(a,b);
		pr= {a,b};

		cout/cin << pr.first;
		cout/cin << pr.second;
		
		// just copy
		pair<int,string>pr2 = pr;

		// reference
		pair<int,string>&pr2 = pr;

		pair<int,int>p_array[]; ❌
		vector<pair<int,int>>p_array;✅
		
*/

// vectors - continues memory block

/*

	Arrays with dynamic size
	vector<data_type_or_container> arr;

	vector<int>arr(N);
	vector<int>arr(N,value);

	arr.push_back(element); // o(1)
	arr[i] = element // o(1)
	arr.size() // O(1)
	arr.pop_back() // o(1)
	vector<int>v2=v1; // just copy O(n)
	vector<int>&v2=v1; //  O(1) reference passed
	Local array - > 10^5
	GLobal array -> 10^7
	vector<int> -> local -10^5
	vector<int> -> global -10^7

	

	//limitations on continous memory

	

		
*/

// pass by reference
void printVector(vector<int>&arr){
	for(int i = 0 ; i < arr.size() ; i++)cout << arr[i] << " ";
	cout << endl;
}

int main(){
	int n;
	cin >> n;

	vector<int>arr(n);
	for(int i = 0 ; i <n ; i++){
		cin >> arr[i];
	}

	printVector(arr);

	vector<int>arr2 = arr;

	arr[2]=200;
	printVector(arr);
	printVector(arr2);


	int* dynamicArray = new int[4];
	// dynamicArray[0]=dynamicArray[1]=dynamicArray[2]=dynamicArray[3]=0;
	dynamicArray[6]=8;
	cout << dynamicArray[5] << endl;
	cout << sizeof(dynamicArray) << endl; 

/*
	pair<int,string>pr;
	// pr = make_pair(1,"One");
	pr={1,"One"};

	cout << pr.first << "- >"<< pr.second << endl;

	// pair<int,string>&pr2 = pr;
	pair<int,string>pr2 = pr;

	cout << pr2.first << "- >"<< pr2.second << endl;

	pr.first = 2;
	cout << pr.first << "- >"<< pr.second << endl;
	cout << pr2.first << "- >"<< pr2.second << endl;		

*/
	return 0;
}