#include<bits/stdc++.h>
using namespace std;

void stringTrim(string &s){

	// remove leading spaces
	int index = 0  ,  n  = s.size();
	while(index<n && s[index]==' ')index++;
	s.erase(0,index);
	// removing extra last spaces
	index  = s.size()-1 ;
	while(index >= 0 && s[index]==' ')index--;
	s.erase(index+1,n-index-1);
}

string reverseWords(string s) {
        stringTrim(s);
        int i = 0 , j = 0 ,n= s.size();
        // reverse whole string
        reverse(s.begin(),s.end()) ;
        // reverse chunks/ word
        while(i < n ){
            while(j < n && s[j] != ' ')j++;
            reverse(s.begin()+i,s.begin()+j);
            while(j < n && s[j]==' ')j++;
            cout << s.size() << endl;
            i = j;
        }
        cout << s.size() << endl;
        return s;
    }

   string reverseWords2(string s) {
        stringTrim(s);
        int i = 0 , j = 0 ,n= s.size();
        // reverse whole string
        reverse(s.begin(),s.end()) ;
        // reverse chunks/ word
        while(i < n ){
            while(j < n && s[j] != ' ')j++;
            reverse(s.begin()+i,s.begin()+j);
            int k = j;
            while(j < n && s[j]==' ')j++;
            if(k!=j && j-k>1){
                s.erase(k+1,j-k-1);
            }
            i = k+1;
            j= i;
            n=s.size();
        }
        return s;
    }

int main(){


	string str = "S     D N   E I R F";
	cout << str << " " << str.size() << endl;

	stringTrim(str);

	cout << str << " " << str.size() << endl; 


	cout << reverseWords2(str) << endl;


	return 0 ;
}