
#include<bits/stdc++.h>
using namespace std;



int main(){

	string s;
	cin >> s;
	vector<int>alpha(26,0);
	for(char &ch:s){
		alpha[ch-'a']++;
	}
	s="";
	for(int i = 0 ; i < 26 ; i++){
		while(alpha[i]>0){
			s.push_back('a'+i);
			alpha[i]--;
		}
		
	}
	cout << s << endl;
	
	return 0;
}