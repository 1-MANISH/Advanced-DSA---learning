#include<bits/stdc++.h>
using namespace std;


long long int factorsCount(long long  int &n ){

	long long int factorCount = 0;
	for(long long  int i = 1; i <= n/i ; i++){
		if(n%i==0){
			long long int j = n/i;
			if(i==j)factorCount+=1;
			else factorCount+=2;
		}
	}
	return factorCount;
}

int main(){

	long long int n , m;
	cin >> n >> m;

	long long int x = factorsCount(n);
	long long int y = factorsCount(m);

	if(x==y){
		cout << "DRAW\n";
	}else if(x>y){
		cout << "A\n";
	}else{
		cout << "B\n";
	}

	
	return  0;
}