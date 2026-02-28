//  string compresasion
#include<bits/stdc++.h>
using namespace std;

void stringCompression(string &s){
	int n = s.size();
	int count = 1;
	char prev = s[0];
	string ans = "";
	for(int i = 1 ;  i < n ; i++){
		if(s[i]==prev)count++;
		else{
			ans+=prev;
			if(count>=2)
				ans+=to_string(count);
			prev=s[i];
			count=1;
		}
	}
	ans+=prev;
	if(count>=2)
		ans+=to_string(count);
	cout << ans << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string str;
		cin >> str;
		stringCompression(str);
	}
	
	return  0;
}