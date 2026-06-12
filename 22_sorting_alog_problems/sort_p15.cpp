
#include<bits/stdc++.h>
using namespace std;

bool compare(pair<string,vector<int>>&p,pair<string,vector<int>>&q){

	if(p.second[0]==q.second[0]){
		if(p.second[3]==q.second[3]){
			if(p.second[1]==q.second[1]){
				return p.first<q.first;
			}
			else return p.second[1]>q.second[1];
		}
		else return p.second[3]>q.second[3];
	}else{
		return p.second[0]>q.second[0];
	}
}

int main(){

	int n ;
	cin >> n;
	vector<pair<string,vector<int>>>students;
	for(int i = 0 ; i  < n ; i++){
		string name;
		int tm,pm,cm,mm;
		cin >> name>>tm>>pm>>cm>>mm;
		students.push_back({name,{tm,pm,cm,mm}});
	}
	sort(students.begin(),students.end(),compare);
	for(auto &student:students){
		cout << student.first << " ";
		for(auto &mark:student.second)cout << mark << " ";
		cout << endl;
	}
	
	return 0;
}