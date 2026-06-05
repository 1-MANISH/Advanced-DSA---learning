#include<bits/stdc++.h>
using namespace std;
#define int long long 

void breakN(int n){

	int bigP = 1;
	while(bigP<=n){
		bigP*=2;
	}
	bigP/=2;
	while(n>=1){
		if(n>=bigP){
			n-=bigP;
			cout << bigP<<" ";
		}
		bigP/=2;
	}
}

signed main(){

	int N;
	cin >> N;
	breakN(N);

	return 0;
}