#include<bits/stdc++.h>
using namespace std;
#define int long long 

void printPrimeFactors(int n){

	int count=0;
    for(int i = 2 ; i<=n/i ; i++){
        if(n%i==0){
        	int c=0;
            while(n%i==0 ){
                n = n/i;
                c++;
            }
            if(c>0){
            	count++;
            }
        }
    }
    if(n!=1){
    	count++;
    }
    cout<< count;
    
}

signed main(){

	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	printPrimeFactors(N);

	return 0;
}