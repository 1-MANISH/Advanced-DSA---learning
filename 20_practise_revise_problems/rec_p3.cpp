
#include<bits/stdc++.h>
using namespace std;

void printDec(int n){

	if(n==0){
		return;
	}
	cout << n << endl;
	printDec(n-1);
}
void printInc(int n){

	if(n==1){
		return;
	}
	printInc(n-1);
	cout << n << endl;
}


int main(){

	int n;
	cin >> n;
	printDec(n);
	printInc(n);

	return 0;
}