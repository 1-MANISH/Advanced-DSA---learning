#include<bits/stdc++.h>
using namespace std;

/*

Given N string , print unique strings
in lexichogaphic order
N<=10&5
|s|<=10^5



Given N String and Q quiries ,

In each query you are given a string
print yes if string presen or not

*/





int main(){

	int n;
	cin >> n;
	unordered_set<string>strs;
	for(int i = 0 ; i< n ; i++){
		string s;
		cin >> s;
		strs.insert(s);
	}
	int q;
	cin >> q;
	while(q--){
		string qs;
		cin >> qs;
		auto it = strs.find(qs);
		if(it==strs.end())cout << "NO\n";
		else cout << "YES\n"; 
	}

	// q(2)

	//q(1)
	// for(auto &str:strs){
	// 	cout << str << endl;
	// }
	
	return 0;
}