#include<bits/stdc++.h>
using namespace std;

/*

Iterators

	-helps us to access containers
	values
	or udpate
	helps us to do all containers
	operations

	pointers like structure
	point to container elements

	vectors - continues

	it point to first Index .begin()
	last+1 Index .end()


	container.begin()
	container.end()

	Declaration
	container :: iterator it = container.begin()

	Values :
		*it - 0 index value
		*(it+1) - 1 index value
	Memory :
		it - 0 index address
		it+1 - 1 index address
	
	Note : 
	it++ next iterator
	it+1 next location

	Always use it++ in case of containers

	Same of vectors it++ == it+1
	because next iteration is same as next location

	In case of Maps and Sets
		- Iterators not equals to next location
		it++ we should use as next iterations

	Summary:
		Iterator : in case of  vectors its continous
		Maps and Sets : are not continous

	vector<int>::iterator it = arr.begin();
	cout << *it << endl;
	
	Syntax : When pair
	vector<pair<int,int>> ::iterator itp;

	itp->first or itp.second
	or
	(*itp).first or (*itp).second

	Note : Short way to write in next
	
	After c++11 we have more ways to write
	auto keywords + range based loops

	
*/

void printVector(vector<int>&arr){
	vector<int>::iterator it = arr.begin();
	while(it!=arr.end()){
		cout << *it<< "" << endl;
		it=it+1;
	}
}

int main(){
	

	int n;
	cin >> n;
	vector<int>arr(n);
	for(int i = 0 ; i < n ; i++){
		cin >> arr[i];
	}

	vector<int>::iterator it = arr.begin();
	// cout << (*it) << endl;
	// cout << (*(it+1)) << endl;

	printVector(arr);

	vector<pair<int,string>>pArr = {
		{1,"One"},
		{2,"Two"},
		{3,"Three"}
	};

	vector<pair<int,string>>::iterator itp;
	itp=pArr.begin();
	for(itp ; itp!=pArr.end();itp++){
		// cout << itp->first << " -> " << itp->second << endl;
		cout << (*itp).first << " -> " << (*itp).second << endl;
	}
}