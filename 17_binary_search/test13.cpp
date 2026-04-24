#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;



int main(){

	vector<int>primes(N,0);
	for(int i = 2 ; i < = N/i  ; i ++){
		for(int j = i*i ; j < N ; j+=i){
			primes[j]=i;
		}
	}

	int q;
	cin >> q;
	while(q--){
		int n,k;
		cin >> n >>k;
		int count= 0 ;
		int bp = primes[n];
		while(bp>1){
			
		}
	}

	return 0;
}