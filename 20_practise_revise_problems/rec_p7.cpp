
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll calPower(int X,int N){
	if(N==1)return X;
	
	ll ans = calPower(X,N/2);
	if(N & 1){
		ans = X*ans*ans;
	}else{
		ans = ans*ans;
	}
	return ans;
}

int main(){

	int X,N;
	cin >> X >> N;
	cout << calPower(X,N);



	return 0;
}