#include<bits/stdc++.h>
using namespace std;

/*
Maps :
	key : value

	Normal : Red black Tree
	Unoredered Map : 

	map<int,string>m;
	auto it = m.begin()
	or
	map<int,string>::iterator it = m.begin()

	*it.first <=>it->first

	m[key]=value
	m.insert({a,b})

	Note : every value of map is a pair
	Note : Normal map keys are sorted in lexicographic increasing order
	
	Normal Map - 
		m.size() => o(1)
		m.insert() => o(log(n)) // n is map current size
		even m[key]-> takes o(log(n))
		cout << m[key] -> o(log(n))

		if value string ->""
		if value int -> 0

		-keys are unique in maps - unoreder_map and maps me
		
		Find and Erase - 
		
		m.find()-> O(log(n))
		auto it = m.find(key) -> returns iterators
		key find -> value ka iterator
		not key find -> it=m.end()

		m.erase(key) -> O(log(n))
		not error on invalid key
		or
		m.erase(it)
		error on invalid it

		m.clear() -> clear all map keys


		m<vector/int/set, string>

		Note : The time of insertion depends
		upon on keys

		map<string,string>m;

		In RBT if we insert new value
		than it will compare to others

		m[s]="random"
		insertion -> TC = s.size() * log(n)
        n map size

    Unordered Maps - 
    	Difference from Normal maps
    	1) inbuilt implementation - hash Table
    	2) TIme complexity
    	3) valid keys
		
		um.insert() 		TC = O(1)
		access 		TC = O(1)
		um.erase() TC = O(1)
		um.clear() TC = O(1)
		um.find() TC = O(1)

		TC = O(1)

		Average time comlexity - O(1)
		in case of collision it slightly more

		Keys can be as complex possible
		but  it should be calculated as hash

		Hash define for DS - so can be used as key in um
		int 
		long 
		string
		char
		double/float

		Not Hash defined - used in maps -  as comparision possible
		Pair
		vector
		set

	Multi Maps - 
		
		similar like map
		multimap<int,int>mm;

		implementation : REB BLACK TREE

		Keys can be duplicated

		in multi maps we can insert keys twice or more than one

		TC = log(n) 

		
		TC=O(log(n))
		insert({a,b})
		ease(k or it)
		find(k)
		count(k) -> number of times keys
		

		size() - O(1)
		empty() -O(1)

*/

void printNormalMap(map<int,string>&m){
	// for(auto it=m.begin() ; it!=m.end() ; it++){
	// 	cout << it->first << " - > " << it->second << endl;
	// }
	// TC = n(log(n))
	for(auto &pr:m){
		cout << pr.first << " -> " << pr.second << endl;
	}
	cout << "-------\n\n";
}
void printUnorderedMap(unordered_map<int,string>&um){
	for(auto &pr:um){
		cout << pr.first << " -> " << pr.second << endl;
	}
	cout << "-------\n\n";
}

void printMultiMap(multimap<int,string>&mm){
	for(auto &pr:mm){
		cout << pr.first << " -> " << pr.second << endl;
	}
	cout << "-------\n\n";
}

int main(){

	multimap<int,string>mm;
	mm.insert({1,"one"});
	mm.insert({2,"Two"});
	mm.insert({1,"one"});
	mm.insert({2,"two"});
	printMultiMap(mm);

	cout << mm.count(2) << endl;

	// unordered_map<int,string>um;
	// um[1]="One";
	// um[2]="Two";
	// um[3]="Three";
	// printUnorderedMap(um);


	// --------------------


	// map<int,string>m;
	// m[1]="One";
	// m[2]="Two";
	// m[3]="Three";
	// printNormalMap(m);

	// auto it = m.find(4);

	// if(it==m.end()){
	// 	cout << "NO KEY FOUND" << endl;
	// 	if(it!=m.end()){
	// 		m.erase(it);	
	// 	}
		
	// 	// m.erase(4);

	// }else{
	// 	cout << it->first << " -> "<< it->second << endl;
	// 	// m.erase(it);
	// 	m.erase(it->first);
	// 	cout << "---------\n\n";
	// 	printNormalMap(m);
	// }

	// m.clear();
	// printNormalMap(m);
	return 0;
}