#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/cpp/requirements-stdmap-key-classes-meet-to-be-valid-keys-cpp/

struct Person{
	int id;
	string name;

	bool operator<(const Person &other) const 
	{
		if(id>other.id)return true;
		else if(id<other.id)return false;
		return name>other.name;

	}
};


int main(){

	map<Person ,int> personMap;

	personMap[Person{1,"Alice"}]=100;
	personMap[Person{2,"Bob"}]=200;
	personMap[Person{3,"Charlie"}]=300;
	personMap[Person{ 1, "Alicea" }] = 100;

	for(auto &pr:personMap){
		cout << pr.first.name << " - > " << pr.second << endl;
	}

	return 0;
}