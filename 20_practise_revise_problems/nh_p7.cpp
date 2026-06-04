#include<bits/stdc++.h>
using namespace std;

void printPrimeFactors(long long int n){

    for(long long int i = 2 ; i<=n/i ; i++){
        if(n%i==0){
        	long long int count=0;
            while(n%i==0 ){
                count++;
                n = n/i;
            }
            if(count>0){
            	cout << i<<"^"<<count<<" ";
            }
        }
    }
    if(n!=1){
    	cout << n <<"^"<< 1;
    }
    
}

int main(){

	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	long long int N;
	cin >> N;

	printPrimeFactors(N);

	return 0;
}