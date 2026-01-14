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

int main(){


	map<int,string>m;
	m[1]="One";
	m[2]="Two";
	m[3]="Three";
	printNormalMap(m);

	auto it = m.find(4);

	if(it==m.end()){
		cout << "NO KEY FOUND" << endl;
		if(it!=m.end()){
			m.erase(it);	
		}
		
		// m.erase(4);

	}else{
		cout << it->first << " -> "<< it->second << endl;
		// m.erase(it);
		m.erase(it->first);
		cout << "---------\n\n";
		printNormalMap(m);
	}

	m.clear();
	printNormalMap(m);
	return 0;
}