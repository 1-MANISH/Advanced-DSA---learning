#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool isSetBit(ll n,int i){
	return n &(1LL<<i);
}

int main(){

	ll N;
	cin >> N;
	ll i = 0 ,count = 0,M=N;	
	while(N>0){
		if(isSetBit(M,i)){
			count++;
		}
		i++;
		N=N>>1;
		if(count>1){
			cout << "NO\n";
			return 0;
		}
	}	
	cout << (count==1 ?"YES\n":"NO\n");



	return 0;
}