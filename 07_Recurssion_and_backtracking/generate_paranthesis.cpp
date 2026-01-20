#include<bits/stdc++.h>
using namespace std;

void generateParenthesis(vector<string>&output , int openingBracket,int closingBracket,string &temp){


        if(openingBracket==0 && closingBracket==0){
            output.push_back(temp);
            return;
        }

        if(openingBracket>0){
            temp.push_back('(');
            generateParenthesis(output,openingBracket-1,closingBracket,temp);
            temp.pop_back();
        }
        if(openingBracket<closingBracket){
            temp.push_back(')');
            generateParenthesis(output,openingBracket,closingBracket-1,temp);
            temp.pop_back();
        }
}


int main(){

	int n;
	cin >> n;

	vector<string>output;
	string temp="";
	int openingBracket = n , closingBracket = n;
	generateParenthesis(output,openingBracket,closingBracket,temp);

    for(auto ele:output)cout << ele << endl;
	return 0;
}