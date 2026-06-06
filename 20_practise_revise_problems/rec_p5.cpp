
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll factorialCal(ll n){
	if(n<=0)return 1;
	return 1LL*n*factorialCal(n-1);
}


int main(){

	ll N;
	cin >> N;
	cout << factorialCal(N);

	return 0;
}