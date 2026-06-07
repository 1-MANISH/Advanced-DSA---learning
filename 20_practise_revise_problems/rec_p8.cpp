
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll sumOfDigits(ll N){
	if(N==0)return 0;

	return (N%10)+sumOfDigits(N/10);

}

int main(){
	ll N;
	cin >> N;
	cout << sumOfDigits(N);

	return 0;
}