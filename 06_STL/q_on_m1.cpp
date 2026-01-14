#include<bits/stdc++.h>
using namespace std;

/*

Given N string print unique string in lexicogrphic 
order with their frequency
N<=10^5
s.size() < =100
Insertion
TC = s.size()*log(10^5)
=> O(100 * log(10^5))
=> O(100*16)
=> O(10^3)
Print
TC = N*log(N) = > 10^5 * 10^1 => 10^6
*/

int main(){

	int n;
	cin >> n;

	map<string,int>sMap;
	for(int i = 0 ; i < n ; i++){
		string s;
		cin>>s;
		sMap[s]++;
	}
	for(auto &it:sMap){
		cout << it.first << " = "<< it.second << endl;
	}

	return 0;
}