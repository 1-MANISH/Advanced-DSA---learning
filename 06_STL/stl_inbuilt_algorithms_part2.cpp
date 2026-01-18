#include<bits/stdc++.h>
using namespace std;

/*

STL inbuilt Algorithms - part2

Lambda Function :
	syntax / template or tempory function
	
	Add 2 to any number : syntax
		[](int x){return x+2}

		Examples
				cout << [](int x){return x+2;}(2) << endl;
		  		cout << [](int x){return pow(x,2);}(4) << endl;
				cout << [](int x,int y){return x+y;}(4,5)<< endl;


	auto func = [](parameter){return ____;}

		func(arguments)


lambdaFunction =>return true or false type functions:

	all_of  : saare match -if ith not mactch false than return otherwise  cheked till matched 

	none_of : none match - Always checked all - if all matched condition return true or otherwise false

	any_of :  any one - if ith  matched return


	func(arr.begin(),arr.end(),lambdaFunction)
*/



void printArray(vector<int>&arr){
	for(auto &ele:arr)cout << ele << " ";
	cout << endl;
}


bool isNegative(int &ele){
	return ele<0;
}
int main(){

	int n;
	cin >> n;
	vector<int>arr(n);
	for(int i = 0 ; i < n ; i++)cin >> arr[i];

	printArray(arr);

	cout << all_of(arr.begin(),arr.end(),[](int ele){
		return ele>0;
	}) << endl;

	cout << all_of(arr.begin(),arr.end(),isNegative) << endl;


	cout << any_of(arr.begin(),arr.end(),[](int &ele){
		return ele==2;
	}) << endl;

	cout << none_of(arr.begin(),arr.end(),[](int &ele){
		return ele%5==0;
	}) << endl;
	
	// lambda fucntion
	// cout << [](int x){return x+2;}(2) << endl;
	// cout << [](int x){return pow(x,2);}(4) << endl;
	// cout << [](int x,int y){return x+y;}(4,5)<< endl;
	// auto multiplyFunc = [](int x,int y){return x*y;};
	// cout << multiplyFunc(6,6) << endl;
	// cout << multiplyFunc(2,6) << endl;

	return 0;
}