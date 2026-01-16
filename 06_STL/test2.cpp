#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	map<int,set<string>>result;
	while(n--){
		string student;
		int marks;
		cin >> student >> marks;
		result[marks].insert(student);
	}
	auto it = result.end();
	--it;
	while(it!=result.begin()){
		auto its = it->second.begin();
		while(its!=it->second.end()){
			cout << *its<< " " << it->first << endl; 
			its++;
		}
		--it;
	};
	auto its = it->second.begin();
	while(its!=it->second.end()){
		cout << *its<< " " << it->first << endl; 
		its++;
	}
	
}