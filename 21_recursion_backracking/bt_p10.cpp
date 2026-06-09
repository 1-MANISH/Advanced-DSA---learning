
#include<bits/stdc++.h>
using namespace std;

void encoding(string &s,int i , string &output,vector<string>&ans){

	if(i==s.size()){
		ans.push_back(output);
		return;
	}

	// take single digit
	output.push_back('a'+s[i]-'1');
	encoding(s,i+1,output,ans);
	output.pop_back();

	// take double digit - if possible
	if(i+1<s.size()){
		int d =   (s[i]- '0')*10 + (s[i+1]-'0') -1 ;
		if(d<26){
			output.push_back('a'+d);
			encoding(s,i+2,output,ans);
			output.pop_back();
		}
		
	}
}


int main(){

	string s;
	cin >> s;
	vector<string>ans;
	string output;

	encoding(s,0,output,ans);

	cout << ans.size() << endl;
	for(string &str:ans)cout << str << endl;



	return 0 ;
}