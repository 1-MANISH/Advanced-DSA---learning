#include<bits/stdc++.h>
using namespace std;

/*

STL inbuilt Algorithms

	sort(begin(),end())
	upper_bound(begin(),end(),ele) // ele ka bda bhai
	lower_bound() // ele or gerater 
	
	//vector and array - O(n)
	min_element:O(n)
		auto it = min_element(arr.begin(),arr.end());
		cout << *it << endl;
	max_element :O(n)
		auto it = max_element(arr.begin(),arr.end());
		cout << *it << endl;
	accumulate :O(n)
		int sum = accumulate(a.begin(),a.end(),intital_value)
	count:O(n)
		int counts = count(a.begin(),.end(),ele);
	find:O(n)
		auto it = find(v.begin(),v.end(),ele)
		cout << *it
	***
	reverse()- O(n) - no copy // array and string
		reverse(v.begin(),v.end());
	
*/

void printArray(vector<int>&arr){
	for(auto &ele:arr)cout << ele << " ";
	cout << endl;
}

int main(){

	int n;
	cin >> n;
	vector<int>arr(n);
	for(int i = 0 ; i < n ; i++)cin >> arr[i];

	printArray(arr);
	cout << *min_element(arr.begin(),arr.end()) << endl;	
	cout << *max_element(arr.begin(),arr.end()) << endl;

	int sum = accumulate(arr.begin(),arr.end(),0);
	cout << sum << endl;

	int counts = count(arr.begin(),arr.end(),6);
	cout << counts << endl;

	auto it = find(arr.begin(),arr.end(),3);
	if(it!=arr.end())
		cout << *it << endl;
	else cout << "ELEMENT NOT FOUND\n\n";

	reverse(arr.begin(),arr.end());
	printArray(arr);
	return 0;
}