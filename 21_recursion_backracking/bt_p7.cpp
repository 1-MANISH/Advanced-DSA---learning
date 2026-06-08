
#include<bits/stdc++.h>
using namespace std;

void generateParenthesis(int &n,int op,int cp,string &output,vector<string>&ans){

	if(op==n && cp==n){
		ans.push_back(output);
		return;
	}

	
	if(op>=cp && op<n){

		// take open
		output.push_back('(');
		generateParenthesis(n,op+1,cp,output,ans);
		output.pop_back();

		// take close
		output.push_back(')');
		generateParenthesis(n,op,cp+1,output,ans);
		output.pop_back();
	}
	else if(cp<n && cp<op){
		// take close
		output.push_back(')');
		generateParenthesis(n,op,cp+1,output,ans);
		output.pop_back();
	}

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