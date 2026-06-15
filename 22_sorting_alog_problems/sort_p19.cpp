
#include<bits/stdc++.h>
using namespace std;

bool compare(string &s1,string &s2){
	return s1+s2>s2+s1;
}

int main(){

	int n ;
	cin >> n;
	vector<string>numbers(n);
	for(int i = 0 ;i < n ; i++){
		int ele;
		cin >> ele;
		numbers[i] = to_string(ele);
		
	}
	sort(numbers.begin(),numbers.end(),compare);
	bool flag=true;
	for(int i = 0 ; i < n ; i++){
		if(numbers[i]!="0"){
			flag=false;
			break;
		}
	}
	if(flag){
		cout << "0" << endl;
		return 0;
	}
	for(auto &number:numbers)cout << number;
	
	return 0;
	
}