
#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,string>&s1,pair<int,string>&s2){
	if(s1.first==s2.first){
		return s1.second<s2.second;
	}
	return s1.first > s2.first;
}

int main(){

	int n ;
	cin >> n;
	vector<pair<int,string>>students;
	for(int i = 0 ; i < n ; i++){
		int marks;
		string name;
		cin >> name >> marks;
		students.push_back({marks,name});
	}

	sort(students.begin(),students.end(),compare);
	for(auto &student:students){
		cout << student.second << " " << student.first << endl;
	}
	
	return 0;
}