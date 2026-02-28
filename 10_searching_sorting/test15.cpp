//longest word
#include<bits/stdc++.h>
using namespace std;

int longestWordLength(string &s){
	int n = s.size();
	int ans = 0;
	string word = "";
	for(int i = 0 ;  i < n ; i++){
		if(s[i]==' '){
			int m = word.size();
			ans = max(ans,m);
			word="";
		}else{
			word+=s[i];
		}
	}
	int m = word.size();
	ans = max(ans,m);
	return ans;
	
}

int main(){

	string str;
	getline(cin,str);
	cout <<longestWordLength(str) << endl;
	
	
	return  0;
}