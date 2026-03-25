#include<bits/stdc++.h>
using namespace std;

bool isPal(string s){
	int i =  0 , j = s.size()-1;
	while(i<j){
		if(s[i]!=s[j])return false;
		i++,j--;
	}
	return true;
}

int main(){

	int n ;
	cin >> n ;
	string s;
	cin >> s;

	for(int i = 0 ; i< n ; i++){
		string sub = "";
		for(int j = i ; j < n ; j++){
			sub+=s[j];
			if(isPal(sub))cout  << sub << endl;;
		}
	}

	
	return  0;
}