
#include<bits/stdc++.h>
using namespace std;

bool compare(string &a,string &b){
	if(a.size()==b.size())
		return a<b;
	return a.size()<b.size();
}

int main(){

	int n ;
	cin >> n;
	vector<string>sarr(n);
	for(int i = 0 ; i < n ; i++)
		cin >> sarr[i];
	
	sort(sarr.begin(),sarr.end(),compare);
	for(auto &str:sarr)cout << str << endl;
	return 0;
}