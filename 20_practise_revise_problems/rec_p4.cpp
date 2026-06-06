
#include<bits/stdc++.h>
using namespace std;

void printRevNumber(string N,int i){
	if(i<0){
		return;
	}
	cout << N[i--];
	printRevNumber(N,i);
}
int main(){

	string N;
	cin >> N;
	printRevNumber(N,N.size()-1);

	return 0;
}