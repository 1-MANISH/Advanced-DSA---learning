//  array rotation
#include<bits/stdc++.h>
using namespace std;

long long int sumOfDigits(string &number){
	long long ds = 0 , n = number.size();
	for(int i = 0 ; i< n ; i++){
		ds+=0LL+(number[i]-'0');
	}
	return ds;
}

int main(){
	string number;
	cin >> number;

	cout << sumOfDigits(number) << endl;
	
	return  0;
}