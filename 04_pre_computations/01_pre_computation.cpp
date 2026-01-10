#include<bits/stdc++.h>
using namespace std;

// print fac(n)
// 1<=T<=10^5
// 1<=N<=10^5
// print ans%m
// m=10^9+7

const int M = 1e9+7;
const int N = 1e5+10;
long long factorial[N];

int main(){

	factorial[0]=factorial[1]=1;
	for(int i = 2 ; i<=1e5 ; i++){
		factorial[i]=(i*factorial[i-1])%M;
	}

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << factorial[n] << endl;
	}
	
	return 0;
}

// TC= O(N)+O(T) = O(N)