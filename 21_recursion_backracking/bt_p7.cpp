
#include<bits/stdc++.h>
using namespace std;

void generateParenthesis(int &n,int op,int cp,string &output,vector<string>&ans){

	
}


int main(){

	int n;
	cin >> n;
	vector<string>ans;
	string output="(";
	generateParenthesis(n,1,0,output,ans);
	cout << ans.size() << endl;
	for(string &p:ans)
		cout<< p << endl;
	

	return 0 ;
}