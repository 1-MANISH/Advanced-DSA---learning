#include<bits/stdc++.h>
using namespace std;


void specialFactor(int n){
	int count = 0 ;
	for(int i  = 1 ; i<= n ; i++){
		if(n%i==0){
			int lastDigit = i%10;
			if(lastDigit==2 || lastDigit ==7){
				cout << i << " ";
				count++;
			}
		}
	}
	if(count==0)cout << -1 << endl;
}

int main(){

	int n;
	cin >> n;
	specialFactor(n);
	
	return 0;
}