#include<bits/stdc++.h>
using namespace std;

bool isChar(char &ch){
	if(ch>='a' && ch<='z')return true;
	else return false;
}

string reverseByType(string s) {
        int i = 0  , j =s.size()-1 , n=s.size();
        while(i<j){
        	while(i< n && i<j && !isChar(s[i]))i++;
        	while(j>=0 && j>i && !isChar(s[j]))j--;
        	if(i<n && j>=0 && i<j){
        		swap(s[i++],s[j--]);
        	}
        }
        i=0 , j = n-1;
        while(i<j){
        	while(i< n && i<j && isChar(s[i]))i++;
        	while(j>=0 && j>i && isChar(s[j]))j--;
        	if(i<n && j>=0 && i<j){
        		swap(s[i++],s[j--]);
        	}
        }

        return s;
   }


int main(){
	string s;
	cin >> s;

	cout << reverseByType(s) << endl;


	return  0;
}