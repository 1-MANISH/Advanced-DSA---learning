
#include<bits/stdc++.h>
using namespace std;

int fibonachi(int n){
	if(n==1 || n==2){
		return n-1;
	}
	return fibonachi(n-1)+fibonachi(n-2);
}

int main(){

	int N;
	cin >> N;
	cout << fibonachi(N);

	return 0;
}