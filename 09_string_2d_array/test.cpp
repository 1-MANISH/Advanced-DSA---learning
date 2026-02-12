#include<bits/stdc++.h>
using namespace std;

bool isStrongPassword(string &s){
	if(s.size()!=10)return false;
	int lc=0,uc=0,sc=0,od=0;
	for(int i = 0 ; i <s.size() ; i++){
		if(s[i]>='a' && s[i]<='z'){
			lc++;
		}else if(s[i]>='A' && s[i]<='Z'){
			uc++;
		}else if(s[i]>='0' && s[i]<='9'){
			od++;
		}else{
			sc++;
		}
	}

	if(lc==0 || uc==0 || sc==0 || od==0)
		return false;
	return true;

}


int main(){
	string str;
	cin >> str;
	cout << (isStrongPassword(str)?"Strong":"Weak")<< endl;


	return  0;
}
