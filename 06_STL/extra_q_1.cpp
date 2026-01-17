#include <bits/stdc++.h>
using namespace std;

// 65-> 90-[A...Z]
// 97-122-[a...z]
/*

A-0
B-1
C-2
D-25
a-26
b-27
c-28
z-

*/

bool isLower(char &ch){
	return ch>='a' && ch<='z';
}

int main() {
	string str;
	cin >> str;
	int n  = str.size();
	vector<int>lascii(52,0);
	for(int i = 0 ; i < n ; i++){
		if(isLower(str[i])){
			lascii[str[i]-'a'+26]++;
		}else{
			lascii[str[i]-'A']++;
		}
	}
	int maxIndex = 0 ;
	for(int i = 0 ; i< 52 ; i++){
		if(lascii[i]>lascii[maxIndex])
			maxIndex=i;
	}
	if(maxIndex<26){
		char ch  = 'A'+(maxIndex);
		cout << ch  << endl;
	}else{
		char ch  = 'a'+maxIndex-26;
		cout << ch<< endl;
	}

}



// #include <bits/stdc++.h>
// using namespace std;
// int main() {
// 	int numOfPeople;
// 	cin >> numOfPeople;    
// 	map<int,multiset<string>>peopleJelousay;
// 	for(int i = 0 ; i< numOfPeople ; i++){
// 		string name;
// 		int x;
// 		cin >> name >> x;
// 		peopleJelousay[x].insert(name);
// 	}
// 	auto it = peopleJelousay.end();
// 	--it;
// 	for(;;it--){
// 		auto peoples = it->second;
// 		for(auto &people:peoples){
// 			cout << people<< " "<< it->first<< endl;
// 		}
// 		if(it==peopleJelousay.begin())break;
// 	}
// }