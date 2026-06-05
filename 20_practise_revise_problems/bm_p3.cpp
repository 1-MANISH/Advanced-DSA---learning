#include<bits/stdc++.h>
using namespace std;
#define int long long

void decimalToBinary(int n){
	if(n==0){
		cout << "0";
		return ;
	}

	int bigP = 1;
	while(bigP<=n){
		bigP*=2;
	}
	bigP/=2;
	while(bigP >0){
		if(bigP <= n ){
			cout << 1;
			n-=bigP;
		}else{
			cout << 0;
		}
		bigP/=2;
	}


}

signed main(){

	int N;
	cin >> N;
	decimalToBinary(N);


	return 0;
}