#include<bits/stdc++.h>
using namespace std;


/*


	Set :
		Set of somethings
		Collections of some elements

	1) Normal Sets
		
		Implementation : Red-Black Tree - Self Balancing Tree
		Declaration:
			set< container or data_type> s;
		
		-Sorted order / No Duplicates
		-s.insert(element) -> O(log(n))
		-access -> o(log(n))
		-access =>auto it =  s.find(ele);
		- Not found than -> s.end()

		-erase -> erase(ele or it) -O(log(n))

		-s.size() -o(1)
		-s.clear() -O(n)

		int map -> access->m[index] or m.find()

	2) Unordered Sets - Use when order does not matters

		Implementation: Hashing - Hash Tables
		O(1)  insert , search , delete operations
		Same as sets
		but not follow any orders
		Unique values only
		s.insert(ele) -O(1)
		s.find(ele) -O(1)
		s.erase(ele-saari delete or it->only ek delete) -O(1)
		
		Note:
			s.erase(ele) -> saare delete
			s.erase(it) -> first delete
		s.size() - o(1)
		s.clear() - O(n)

		Note : we  can't put complex data strucute
		like pair ,set or some others which hash computation is not available


	3) Multi Sets ***
		RBT
		Allow multiple values to 
		insert
			
		multiset<container>ms;

		ms.insert() -Log(n)
		ms.find() -Log(n) - return first value iterator
		ms.erase() -Log(n) - delete first element
		

		ms.size()
		ms.clear()

		used in/with priority_queue
		sorted order storage
*/


void printNormalSet(set<string>&s){
	for(auto &ele:s)cout << ele << endl;

	// for(auto it=s.begin();it!=s.end() ; it++)
	// 	cout << *it << endl;
	cout << "-----------\n\n";
}

void printUnoderedSet(unordered_set<int>&us){
	for(auto &ele:us)cout << ele<<endl;
		cout << "------\n\n";
}
void printMultiSet(multiset<int>&ms){
	for(auto &ele:ms)cout << ele<<endl;
		cout << "------\n\n";
}
int main(){

	multiset<int>ms;
	int n;
	cin >> n;
	for(int i = 0  ; i < n ; i++){
		int num;
		cin >> num;
		ms.insert(num);
	}
	printMultiSet(ms);
	cout << ms.size() << endl << endl;

	auto it = ms.find(1);
	if(it!=ms.end()){
		cout << *it << endl;
		ms.erase(it);
		cout  << endl;
	}
	printMultiSet(ms);
	cout << ms.size() << endl;

	/*
	unordered_set<int> us = {1,2,3,4,1,2};

	printUnoderedSet(us);
	cout << us.size() << endl;

	auto it = us.find(3);
	if(it!=us.end()){
		cout << *it << endl;
		us.erase(it);
		cout << endl;
	}
	printUnoderedSet(us);
	cout << us.size();

	*/

	/*

	set<string>s;
	s.insert("abc");
	s.insert("jkl");
	s.insert("abc");

	printNormalSet(s);
	// set<string>::iterator it;
	auto it = s.find("abc");
	if(it!=s.end()){
		cout << (*it) << endl;
		s.erase(it);
	}

	cout << s.size() << endl;
	cout << "----------\n";
	printNormalSet(s);
	// s.clear();
	// cout << s.size() << endl;

	*/


	return 0 ;
}