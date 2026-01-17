#include <bits/stdc++.h>
using namespace std;

/*

Extensivaly used in c++
Conditions :
1) Array or vector should be sorted Than -log(n)
2) For unsorted - O(n)
3) return location/iterator


upper_bound() : return location/iterator-Log(n)
	If even elements presents than also
	next element finds	
upperBound(5)=>7
upper_bound(9)=>25
upper_bound(7)=>8
upper_bound(25)=>arr.end()

lower_bound() : return location/iterator-Log(n)
	- IF we wants to find a element
	than its find that ele or just its bda bhai

lower_bound(4) => 4
lower_bound(5)=>5
lower_bound(7)=>7
lower_bound(6)=>7
lower_bound(26)=> arr.end()


For Array
int* lower = lower_bound(arr,arr+n,ele)
int* upper  = upper_bound(arr,arr+n,ele)

For Vector
auto it1 = lower_bound(arr.begin(),arr.end(),ele)
auto it2  = upper_bound(arr.begin(),arr.end(),ele)


// Boths are already sorted-as maps and sets
Maps
map<int,int>m;
auto it = m.lower_bound(ele);-log(n)
it.first and it.second as pair
Note: not use below one
auto it = lower_bound(m.begin(),m.end(),ele)-O(N)

Sets
set<int>s;

auto it = s.lower_bound(ele);-log(n)
Note: not use below one
auto it = lower_bound(s.begin(),s.end(),ele)-O(N)

Also for pairs
inside set and maps
Also for strings 

in vector and array - Binary search to find lower and upper bounds

in set and maps -  Trees tree traversal used to find lower and upper bounds

*/

void printArr(int arr[],int n){
	for(int i = 0 ; i < n ; i++){
		cout << arr[i]<< " ";
	}cout<< "------------\n\n";
}

void printSet(set<int>&s){
	for(auto &ele:s)cout << ele << " ";
		cout<< "------\n\n";
}
void printMap(map<int,int>&m){
	for(auto &ele:m)cout << ele.first << " "<< ele.second << endl;
		cout<< "------\n\n";
}

int main(){

	int n;
	cin >> n;
	map<int,int>m;
	for(int i = 0 ; i < n ; i++){
		int x;
		cin >> x;
		m[x]++;
	}
	printMap(m);
	// auto it = lower_bound(m.begin(),m.end(),5);//o(log(n))
	auto it = m.lower_bound(9);//o(log(n))
	cout << (*it).first << endl;


	// int n;
	// cin >> n;
	// set<int>s;
	// for(int i = 0 ; i < n ; i++){
	// 	int x;
	// 	cin >>x;
	// 	s.insert(x);
	// }
	// printSet(s);
	// // auto it = lower_bound(s.begin(),s.end(),5);//o(log(n))
	// auto it = s.lower_bound(5);//o(log(n))
	// cout << *it << endl;



	/*
		int n;
		cin >> n;
		int arr[n];
		for(int i = 0 ; i < n ; i++)cin >> arr[i];

		sort(arr,arr+n);
		printArr(arr,n);

		int *lower = lower_bound(arr,arr+n,25);
		int *upper = upper_bound(arr,arr+n,6);
		if(lower==arr+n){
			cout << "no lower bound\n";
		}else{
			cout <<"lower bound =  "<< *(lower)<< endl;	
		}
		if(upper==arr+n){
			cout << "no upper bound\n";
		}
		else{
			cout <<"upper bound =  "<< *(upper)<< endl;
		}

		vector<int>vArr={1,2,3,5,6};


		auto lower1 = lower_bound(vArr.begin(),vArr.end(),6);
		auto upper1 = upper_bound(vArr.begin(),vArr.end(),5);
		if(lower1==vArr.end()){
			cout << "no lower bound\n";
		}else{
			cout <<"lower bound =  "<< (*lower1)<< endl;	
		}
		if(upper1==vArr.end()){
			cout << "no upper bound\n";
		}
		else{
			cout <<"upper bound =  "<< (*upper1)<< endl;
		}

	*/


	return 0;
}