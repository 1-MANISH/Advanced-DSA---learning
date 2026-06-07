
#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll nSum(ll n){
	if(n==0){
		return 0;
	}
	return 0LL+n+nSum(n-1);
}

int main(){

	ll N;
	cin >> N;
	cout << nSum(N);

	return 0;
}