#include<bits/stdc++.h>
using namespace std;

/*


Nesting in map , set

//comparision possible - ordered
map<set<int>,int>m;
set<pair<int,string>>s;
map<int,set<int>>m;
map<vector<int>,int>m
map<pair<string,string>,vector<int>>m

Values can be anything

//unordered -  hash value possible than
or custom comparator define krna pdega

*/

int main(){

	int n;
	cin >> n;
	map<pair<string,string>,vector<int>>m;
	while(n--){
		string fn,ln;
		int ns;
		cin >> fn >> ln >> ns;
		for(int i = 0  ; i < ns ; i++){
			int marks;
			cin >> marks;
			m[{fn,ln}].push_back(marks);
		}
	}
	// print
	for(auto &student:m){
		cout << student.first.first << " " << student.first.second << " ( ";
		for(int i = 0  ; i < student.second.size() ; i++){
			cout << student.second[i] << " , ";
		}
		cout << " ) " << endl;
	}



	return 0;
}