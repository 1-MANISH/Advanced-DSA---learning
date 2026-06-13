
#include<bits/stdc++.h>
using namespace std;

bool compare(string &s1,string &s2){
	int n = s1.size() , m = s2.size();
	if(n==m){
		return s1>s2;
	}else {
		int i = 0;
		while(i<min(n,m)){
			if(s1[i]==s2[i])i++;
			else return s1[i]>s2[i];
		}
		return n<m ? s1[--i]<s2[m-1] : s1[n-1]>s2[--i];
	}
}

int main(){

	int n , m = 0;
	cin >> n;
	vector<string>numbers(n);
	for(int i = 0 ;i < n ; i++){
		cin >> numbers[i];
		if(numbers[i]=="0")m++;
	}
	if(n==m){
		cout << 0 << endl;
		return 0;
	}	
	sort(numbers.begin(),numbers.end(),compare);
	for(auto &number:numbers)cout << number;
	
	// return 0;
	
}