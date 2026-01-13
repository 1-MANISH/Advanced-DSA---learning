#include<bits/stdc++.h>
using namespace std;

/*

Short code - for iterators

Auto and Range based loops

	Range based loops-

	Traditional : for(int i = 0 ; i < n ; i++) cout << arr[i]

	Range based : for(int value : arr) cout << value;

	Note : here value is copy of arr[i]th
	So we can Use

	Actually use than use &
	for(int &value : arr) cout << value;

	Note : if WE not modifying our values than
	dont use & as reference pass


	Auto Keyword : auto its type - dynamic data type allocation

	typeid(data_type or container).name() - to print data types

	Example
		auto value = 1;

	vector<int>::iterator it=arr.begin();
	auto it = arr.begin();

*/

void printVector(vector<int>&arr){
	// for(int &value : arr){
	// 	cout << value << " " << endl;
	// 	// value++;
	// }cout << endl;


	for(auto &value : arr){
		cout << value << " " << endl;
		// value++;
	}cout << endl;
}

void printPVector(vector<pair<int,string>>&pArr){
	// for(pair<int,string> &pValue:pArr){
	// 	cout << pValue.first << " " << pValue.second << endl;
	// }cout << endl;


	for(auto &pValue:pArr){
		cout << pValue.first << " " << pValue.second << endl;
	}cout << endl;
}

int main(){

	int n , m;
	cin >> n >> m;
	vector<int>arr(n);
	vector<pair<int,string>>pArr(m);
	for(int i = 0 ; i < n ; i++)cin >> arr[i];
	for(int i = 0 ; i < m ; i++)cin >> pArr[i].first >> pArr[i].second;
	printVector(arr);
	printPVector(pArr);
	printVector(arr);

	auto value = 1.0;
	auto boolValue = 1;

	cout << value << " "<< boolValue << endl;
	cout << typeid( value).name() << " " << typeid(boolValue).name() << endl;
	cout << typeid(arr).name() << endl << endl;

	vector<int>::iterator it=arr.begin();
	cout << (*it) << endl;

	auto itShort = arr.begin();
	cout << *itShort << endl;


	return 0;
}