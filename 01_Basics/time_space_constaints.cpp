#include<bits/stdc++.h>
using namespace std;

int main(){

	int N = 1000 ;
	long long int ct=0;
	for(int i =1 ; i<=N ; i++){
		ct=0;
		for(int j = 1 ; j<=i ; j++)ct=ct+j;
	}cout << ct << endl;

cout <<(  (1LL*N*(N+1))/2+0LL) << endl;

	return 0;
}