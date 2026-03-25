
#include<bits/stdc++.h>
using namespace std;

bool isVowel(char &ch){
	if(ch=='a' || ch=='e' || ch =='i' || ch=='o' || ch=='u')
		return true;
	return false;
}

int main(){

	
	int n ,q;
	cin >> n >> q;
	string str ;
	cin >> str;
	for(auto &ch:str){
		if(ch>='A' && ch<='Z'){
			ch='a'+(ch-'A');
		}
	}
	vector<pair<int,int>>prefix(n+1,{0,0});
	for(int i = 1 ; i <= n ; i++){
		prefix[i].first=prefix[i-1].first + (isVowel(str[i-1]) ? 1:0 );
		prefix[i].second=prefix[i-1].second + (isVowel(str[i-1]) ? 0:1 );
	}
	
	while(q--){
		int l ,r;
		cin >> l >> r;
		int vCount = prefix[r].first-prefix[l-1].first;
		int cCount = prefix[r].second-prefix[l-1].second;
		cout << (vCount==cCount?"YES\n":"NO\n");

	}
	
	

	



	
	return  0;
}