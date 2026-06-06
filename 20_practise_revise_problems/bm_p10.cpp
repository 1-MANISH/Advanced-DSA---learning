#include<bits/stdc++.h>
using namespace std;

int bitCount(int n){
	int count = 0 , i = 0 , m = n;
	while(n>0){
		if( m & (1<<i))count++;
		i++;
		n=n>>1;
	}
	return count;
}

int main(){
	int n;
	cin >> n;
	cout << bitCount(n);

	return 0;
}