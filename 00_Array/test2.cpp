#include<bits/stdc++.h>
using namespace std;

bool isAlmostPrime(int &n){
	int divisorCount = 0;
	for(int i = 1 ; i <= n ; i++){
		if(n%i==0)divisorCount++;
	}
	return divisorCount<=4;
}

void almostPrimePrint(int &n){

	for(int i = 1 ; i <=n ; i++){
		if(isAlmostPrime(i)) cout <<i<< " ";
	}
}

int main(){

	int n;
	cin >> n;
	almostPrimePrint(n);

	return 0;
}