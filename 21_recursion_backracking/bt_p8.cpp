
#include<bits/stdc++.h>
using namespace std;

vector<string>maping = {
		"",
		"",
		"abc",
		"def",
		"ghi",
		"jkl",
		"mno",
		"pqrs",
		"tuv",
		"wxyz",
};

void keyCombination(string &s,int i,string &output,vector<string>&ans){

	if(i==s.size()){
		ans.push_back(output);
		return;
	}
	int index = s[i]-'0';
	for(int j = 0 ; j < maping[index].size();j++){
		output+=maping[index][j];
		keyCombination(s,i+1,output,ans);
		output.pop_back();
	}


}


int main(){

	string s;
	cin >> s;

	vector<string>ans;
	string output;

	keyCombination(s,0,output,ans);

	cout << ans.size() << endl;
	for(string &str:ans)
		cout << str << endl;

	return 0 ;
}