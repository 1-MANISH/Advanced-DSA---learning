
#include<bits/stdc++.h>
using namespace std;


long long int countFactors(long long int &n){
	int counts = 0;
	for(long long int i = 1 ; i * i<= n ; i++){
			if(n%i==0){
				long long int j = n/i;
				if(i==j)counts++;
				else {counts+=2;}
			}
	}
	return counts;
}

int main(){

	long long int n;
	cin >> n;
	
	cout << countFactors (n) << endl;
	return  0;
}