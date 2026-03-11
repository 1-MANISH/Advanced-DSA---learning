
#include<bits/stdc++.h>
using namespace std;


bool isPrime(long long int &n){

	if(n<1)return false;
	long long int  count = 0;

	for(long long int i = 1 ; i*i <=n ; i++){
		if(n%i==0){
			long long int j = n/i;
			if(i==j)count++;
			else count+=2;
		}
		
	}

	return count==2;
}

int main(){

	long long int n;
	cin >> n;
	
	cout << (isPrime(n)?"YES":"NO")<< endl;
	return  0;
}