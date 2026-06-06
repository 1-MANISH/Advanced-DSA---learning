#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >>n;

	int xorSum = 0 ;
	for(int i = 0 ; i < n ; i++){
		int arrEle;
		cin >> arrEle;
		xorSum ^= arrEle;
	}
	cout << xorSum << endl;

	return 0;
}