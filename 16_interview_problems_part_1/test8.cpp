/*
Q:
205. Isomorphic Strings
*/
#include<bits/stdc++.h>
using namespace std;

bool isIsomorphic(string &s, string &t) {
        int n = s.size();
        unordered_map<char,char>charMapS;
        unordered_map<char,char>charMapT;
        for(int i = 0 ; i < n ; i++){
            if(charMapS[s[i]]==NULL && charMapT[t[i]]==NULL) {
                charMapS[s[i]]=t[i];
                charMapT[t[i]]=s[i];
            }
            else {
                if(charMapS[s[i]] != t[i])return false;
                if(charMapT[t[i]] != s[i])return false;
            }
        }return true;
}

int main(){

	string s,t;
	cin >> s >> t;

	cout << isIsomorphic(s,t) <<endl;

	
	return  0;
}