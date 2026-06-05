#include<bits/stdc++.h>
using namespace std;
#define int long long 

void binaryToDecimal(string &n){
	int ans = 1 , ansNumber = 0 , size = n.size();
	for(int i = size-1 ; i >=0 ; i--){
		ansNumber+=(n[i]=='1' ? ans : 0);
		ans=ans<<1;
	}
	cout << ansNumber << endl;
}

signed main(){

	string N;
	cin >> N;
	binaryToDecimal(N);

	return 0;
}